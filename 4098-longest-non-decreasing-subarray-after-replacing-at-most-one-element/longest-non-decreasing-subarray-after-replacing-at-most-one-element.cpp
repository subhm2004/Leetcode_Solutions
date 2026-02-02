class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        /*
        ========================================================
        CORE IDEA - DO DIRECTION SE SOCHO!
        ========================================================
        
        PROBLEM KYA HAI?
        ---------------
        - Hume ek element replace kar sakte hain (ya koi bhi nahi)
        - Longest non-decreasing subarray chahiye
        - Non-decreasing matlab: arr[i] >= arr[i-1]
        
        APPROACH:
        ---------
        Har index 'i' ke liye calculate karo:
        
        1. LEFT[i]: Index i tak LEFT se kitna lamba non-decreasing sequence hai?
                    (i ko include karke, left se right direction me)
        
        2. RIGHT[i]: Index i se RIGHT tak kitna lamba non-decreasing sequence hai?
                     (i ko include karke, right se left direction me)
        
        Phir har index ko REPLACEMENT POINT consider karo:
        - Agar index 'i' ko replace kare to kya maximum length milegi?
        
        ========================================================
        STEP 1: LEFT ARRAY BANAO
        ========================================================
        left[i] = Index i TAK (including i) LEFT se kitni lambi
                  non-decreasing sequence hai
        
        Example:
        nums =  [1, 2, 3, 1, 2]
        
        left[0] = 1  → [1] (sirf ek element)
        
        left[1]: nums[1]=2 >= nums[0]=1? YES
                 → left[1] = left[0] + 1 = 2
                 → Sequence: [1, 2]
        
        left[2]: nums[2]=3 >= nums[1]=2? YES
                 → left[2] = left[1] + 1 = 3
                 → Sequence: [1, 2, 3]
        
        left[3]: nums[3]=1 >= nums[2]=3? NO (1 < 3)
                 → BREAK! New sequence start
                 → left[3] = 1
                 → Sequence: [1]
        
        left[4]: nums[4]=2 >= nums[3]=1? YES
                 → left[4] = left[3] + 1 = 2
                 → Sequence: [1, 2]
        
        Final left array: [1, 2, 3, 1, 2]
        
        INTERPRETATION:
        left[i] = "Mujhe (index i) tak aa kar kitne consecutive
                   non-decreasing elements mile LEFT se start karke"
        */
        vector<int> left(n), right(n);
        
        // Base case: Pehla element khud se 1 length ka sequence hai
        left[0] = 1;
        
        // Left to right traverse karo
        for (int i = 1; i < n; i++) {
            // Check: Current element previous se >= hai?
            if (nums[i-1] <= nums[i]) {
                // YES → Previous sequence extend ho gayi
                left[i] = left[i - 1] + 1;
            }
            else {
                // NO → Sequence break! Nayi sequence start
                left[i] = 1;
            }
        }
        
        /*
        ========================================================
        STEP 2: RIGHT ARRAY BANAO
        ========================================================
        right[i] = Index i SE (including i) RIGHT tak kitni lambi
                   non-decreasing sequence hai
        
        IMPORTANT: Non-decreasing RIGHT se left jate waqt matlab:
                   nums[i] <= nums[i+1] hona chahiye
        
        Example (same nums):
        nums =  [1, 2, 3, 1, 2]
        
        right[4] = 1  → [2] (last element)
        
        right[3]: nums[3]=1 <= nums[4]=2? YES
                  → right[3] = right[4] + 1 = 2
                  → Sequence: [1, 2]
        
        right[2]: nums[2]=3 <= nums[3]=1? NO (3 > 1)
                  → BREAK! New sequence
                  → right[2] = 1
                  → Sequence: [3]
        
        right[1]: nums[1]=2 <= nums[2]=3? YES
                  → right[1] = right[2] + 1 = 2
                  → Sequence: [2, 3]
        
        right[0]: nums[0]=1 <= nums[1]=2? YES
                  → right[0] = right[1] + 1 = 3
                  → Sequence: [1, 2, 3]
        
        Final right array: [3, 2, 1, 2, 1]
        
        INTERPRETATION:
        right[i] = "Mujhse (index i) start karke RIGHT tak kitne
                    consecutive non-decreasing elements hain"
        */
        
        // Base case: Last element khud se 1 length ka sequence hai
        right[n - 1] = 1;
        
        // Right to left traverse karo
        for (int i = n - 2; i >= 0; i--) {
            // Check: Current element next se <= hai?
            if (nums[i] <= nums[i + 1]) {
                // YES → Aage ki sequence me merge ho sakta hai
                right[i] = right[i + 1] + 1;
            }
            else {
                // NO → Sequence break! Nayi sequence
                right[i] = 1;
            }
        }
        
        /*
        ========================================================
        STEP 3: ANSWER INITIALIZE - WITHOUT REPLACEMENT
        ========================================================
        
        Pehle dekho: Bina kisi replacement ke kitna max mil sakta hai?
        Ye simply left array ka maximum value hoga
        
        Example:
        left = [1, 2, 3, 1, 2]
        max = 3 (index 2 par, sequence [1,2,3])
        
        WHY?
        left[i] already represents longest non-decreasing ending at i
        So maximum of all left[i] = longest without any change
        */
        int ans = 1;
        
        // Sabse lamba existing non-decreasing sequence
        for (int i = 0; i < n; i++)
            ans = max(ans, left[i]);
        
        /*
        ========================================================
        STEP 4: TRY REPLACING EACH INDEX
        ========================================================
        
        Ab har index 'i' ko REPLACEMENT POINT consider karo
        
        Agar nums[i] ko replace karte hain to 4 CASES possible hain:
        
        CASE 1: Sirf nums[i] ko kuch bhi value se replace karo
                Length = 1
        
        CASE 2: nums[i] ko replace karke LEFT sequence extend karo
                Condition: i > 0 hona chahiye
                Length = left[i-1] + 1
                
                Example:
                nums = [1, 2, 5, 9]
                Index i=2 (value=5) replace karo
                left[1] = 2 (sequence [1,2])
                Replace nums[2] with 3
                New sequence: [1, 2, 3] → length = 2+1 = 3
        
        CASE 3: nums[i] ko replace karke RIGHT sequence extend karo
                Condition: i+1 < n hona chahiye
                Length = right[i+1] + 1
                
                Example:
                nums = [1, 9, 2, 3]
                Index i=1 (value=9) replace karo
                right[2] = 2 (sequence [2,3])
                Replace nums[1] with 2
                New sequence: [2, 2, 3] → length = 2+1 = 3
        
        CASE 4: nums[i] ko replace karke LEFT aur RIGHT dono join karo
                Conditions:
                - i > 0 AND i+1 < n
                - nums[i-1] <= nums[i+1]
                
                WHY nums[i-1] <= nums[i+1]?
                Kyunki hum nums[i] ko kisi bhi value se replace kar sakte hain
                So agar nums[i-1] <= nums[i+1], to hum nums[i] ko aise
                value se replace kar sakte hain jo dono ke beech me ho
                
                Length = left[i-1] + 1 + right[i+1]
                
                Example:
                nums =  [1, 2, 3, 1, 2]
                        [0  1  2  3  4]
                left =  [1, 2, 3, 1, 2]
                right = [3, 2, 1, 2, 1]
                
                Try replacing index i=3 (value=1):
                nums[2] = 3
                nums[4] = 2
                Is 3 <= 2? NO! Skip Case 4
                
                Try replacing index i=2 (hypothetically):
                nums[1] = 2
                nums[3] = 1
                Is 2 <= 1? NO! Skip Case 4
                
                Better example:
                nums = [1, 2, 5, 3, 4]
                Replace i=2 (value=5):
                nums[1]=2, nums[3]=3
                Is 2 <= 3? YES!
                left[1]=2, right[3]=2
                Replace nums[2] with 2.5 or 3
                New: [1, 2, 2.5, 3, 4] or [1, 2, 3, 3, 4]
                Length = 2 + 1 + 2 = 5
        */
        
        // Har index ko replacement point try karo
        for (int i = 0; i < n; i++) {
            int best = 1;  // Minimum 1 to mil hi jayega (khud ko replace karke)
            
            /*
            CASE 2: LEFT sequence extend karo
            ---------------------------------
            Agar pehle element (i=0) nahi hai, to left sequence extend kar sakte hain
            
            Example:
            nums = [1, 2, 9, 3]
            i=2, left[1]=2
            Replace nums[2] with 3
            Length = 2 + 1 = 3 → [1, 2, 3]
            */
            if (i > 0) 
                best = max(best, left[i - 1] + 1);
            
            /*
            CASE 3: RIGHT sequence extend karo
            ----------------------------------
            Agar last element (i=n-1) nahi hai, to right sequence extend kar sakte hain
            
            Example:
            nums = [9, 1, 2, 3]
            i=0, right[1]=3
            Replace nums[0] with 1
            Length = 3 + 1 = 4 → [1, 1, 2, 3]
            */
            if (i + 1 < n) 
                best = max(best, right[i + 1] + 1);
            
            /*
            CASE 4: LEFT aur RIGHT dono join karo
            --------------------------------------
            Ye MOST POWERFUL case hai!
            
            Conditions check karo:
            1. i > 0 (left side exist karti hai)
            2. i + 1 < n (right side exist karti hai)
            3. nums[i-1] <= nums[i+1] (bridge possible hai)
            
            Agar teeno conditions true:
            nums[i] ko replace karke left aur right ko connect karo
            
            
            */
            if (i > 0 && i + 1 < n) {
                // Check: Kya left aur right ko bridge kar sakte hain?
                if (nums[i - 1] <= nums[i + 1]) {
                    // YES! Bridge possible hai
                    // nums[i] ko aise value se replace karo jo beech me fit ho jaye
                    best = max(best, left[i - 1] + 1 + right[i + 1]);
                }
                /*
                WHY nums[i-1] <= nums[i+1]?
                --------------------------
                Kyunki hum nums[i] ko KISI BHI value se replace kar sakte hain
                
                Agar nums[i-1] <= nums[i+1]:
                → nums[i] = nums[i-1] (ya kuch beech me) rakh sakte hain
                → Example: nums[i-1]=2, nums[i+1]=5
                          → nums[i] = 2 or 3 or 4 or 5 (kuch bhi chalega)
                
                Agar nums[i-1] > nums[i+1]:
                → Bridge impossible!
                → Example: nums[i-1]=5, nums[i+1]=2
                          → nums[i] = ? (5 se >= aur 2 se <= impossible!)
                */
            }
            
            // Har index ke liye best ko track karo
            ans = max(ans, best);
        }
        
        /*
        ========================================================
        FINAL ANSWER
        ========================================================
        ans me ab maximum length hai jo:
        - Ya to bina replacement (left array ka max)
        - Ya ek replacement ke saath (Case 2, 3, ya 4)
        */
        return ans;
    }
};

/*
========================================================
COMPLETE TRACE - EXAMPLE 1
========================================================
Input: nums = [1, 2, 3, 1, 2]

STEP 1: Build left array
------------------------
i=0: left[0] = 1
i=1: 2 >= 1? YES → left[1] = 1+1 = 2
i=2: 3 >= 2? YES → left[2] = 2+1 = 3
i=3: 1 >= 3? NO  → left[3] = 1
i=4: 2 >= 1? YES → left[4] = 1+1 = 2

left = [1, 2, 3, 1, 2]

STEP 2: Build right array
-------------------------
i=4: right[4] = 1
i=3: 1 <= 2? YES → right[3] = 1+1 = 2
i=2: 3 <= 1? NO  → right[2] = 1
i=1: 2 <= 3? YES → right[1] = 1+1 = 2
i=0: 1 <= 2? YES → right[0] = 2+1 = 3

right = [3, 2, 1, 2, 1]

STEP 3: Initial answer (no replacement)
---------------------------------------
ans = max(left) = max(1,2,3,1,2) = 3

STEP 4: Try replacing each index
---------------------------------

i=0:
  best = 1
  i+1 < n? YES → best = max(1, right[1]+1) = max(1, 3) = 3
  ans = max(3, 3) = 3

i=1:
  best = 1
  i > 0? YES → best = max(1, left[0]+1) = max(1, 2) = 2
  i+1 < n? YES → best = max(2, right[2]+1) = max(2, 2) = 2
  i>0 && i+1<n? YES
    nums[0]=1 <= nums[2]=3? YES
    best = max(2, left[0]+1+right[2]) = max(2, 1+1+1) = max(2, 3) = 3
  ans = max(3, 3) = 3

i=2:
  best = 1
  i > 0? YES → best = max(1, left[1]+1) = max(1, 3) = 3
  i+1 < n? YES → best = max(3, right[3]+1) = max(3, 3) = 3
  i>0 && i+1<n? YES
    nums[1]=2 <= nums[3]=1? NO (2 > 1) → Skip Case 4
  ans = max(3, 3) = 3

i=3:
  best = 1
  i > 0? YES → best = max(1, left[2]+1) = max(1, 4) = 4  ← KEY STEP!
  i+1 < n? YES → best = max(4, right[4]+1) = max(4, 2) = 4
  i>0 && i+1<n? YES
    nums[2]=3 <= nums[4]=2? NO (3 > 2) → Skip Case 4
  ans = max(3, 4) = 4  ← ANSWER UPDATE!

i=4:
  best = 1
  i > 0? YES → best = max(1, left[3]+1) = max(1, 2) = 2
  ans = max(4, 2) = 4

FINAL ANSWER: 4

EXPLANATION:
Replace nums[3]=1 with 3
New array: [1, 2, 3, 3, 2]
Longest: [1, 2, 3, 3] (length 4)

========================================================
TIME COMPLEXITY: O(n)
========================================================
- Build left array: O(n)
- Build right array: O(n)
- Find initial max: O(n)
- Try all replacements: O(n)
Total: O(n)

SPACE COMPLEXITY: O(n)
========================================================
- left array: O(n)
- right array: O(n)
Total: O(n)

========================================================
KEY INSIGHTS:
========================================================
1. Precompute kar lo dono directions se longest sequences
2. Har index pe efficiently try kar sakte ho replacement
3. Bridge case (Case 4) sabse powerful hai
4. nums[i-1] <= nums[i+1] check important hai bridge ke liye

Samjh aa gaya bilkul? 🚀
*/