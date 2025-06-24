/*
PROBLEM: Do indices i aur j find karne hain jo satisfy kare:
1. |i - j| >= indexDifference
2. |nums[i] - nums[j]| >= valueDifference ise solve krnege to do values aayegi search 1 or sreach 2 
search 1 banegi Value >= nums[i] + valueDifference
search 2 agegi  Value <= nums[i] - valueDifference isme +1 kr denge taki lower bound sahi se anwer de ske 
Koi bhi valid pair [i, j] return karo ya [-1, -1] agar koi nahi mila.

APPROACH: Set use karke sorted (value, index) pairs maintain karte hain efficient search ke liye
*/

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        
        // Set mein pairs {value, index} store karte hain jo value se sorted rehte hain
        // Ye values pe binary search karne mein help karta hai
        set<pair<int, int>> elements; // {value, index}
        
        // indexDifference se start karte hain taaki valid elements mil sake compare karne ke liye
        for (int i = indexDifference; i < n; ++i) {
            
            // Position (i - indexDifference) pe jo element hai use insert karte hain
            // Ye ensure karta hai ki |i - (i - indexDifference)| = indexDifference ✓
            elements.insert({nums[i - indexDifference], i - indexDifference});
            
            // SEARCH 1: Value >= nums[i] + valueDifference find karo
            // Agar mil gaya, to |nums[found] - nums[i]| >= valueDifference ✓
            auto it1 = elements.lower_bound({nums[i] + valueDifference, -1});
            if (it1 != elements.end()) {
                // Valid pair mil gaya: current i aur stored index
                return {i, it1->second};
            }
            
            // SEARCH 2: Value <= nums[i] - valueDifference find karo
            // Hum (nums[i] - valueDifference + 1) search karte hain aur ek step peeche jaate hain
            auto it2 = elements.lower_bound({nums[i] - valueDifference + 1, -1});
            if (it2 != elements.begin()) {
                --it2; // Sabse bada element <= nums[i] - valueDifference pe move karo
                // Ab |nums[i] - nums[it2->first]| >= valueDifference ✓
                return {i, it2->second};
            }
        }
        
        // Koi valid pair nahi mila
        return {-1, -1};
    }
};

/*
DETAILED LINE-BY-LINE BREAKDOWN:

1. set<pair<int, int>> elements;
   - {value, index} pairs store karta hai
   - Automatically value se sorted rehta hai (primary), phir index se (secondary)
   - O(log n) search operations allow karta hai

2. for (int i = indexDifference; i < n; ++i)
   - indexDifference se start karte hain kyunki humein |i-j| >= indexDifference chahiye
   - Ye ensure karta hai ki hamesha kam se kam ek valid element ho compare karne ke liye

3. elements.insert({nums[i - indexDifference], i - indexDifference});
   - Jo element exactly indexDifference distance pe hai use add karte hain current position se
   - Distance = |i - (i - indexDifference)| = indexDifference ✓

4. auto it1 = elements.lower_bound({nums[i] + valueDifference, -1});
   - Pehla element search karte hain jiska value >= (nums[i] + valueDifference) hai
   - -1 dummy value hai; humein sirf value part se matlab hai
   - Agar aisa element exists hai, to |element_value - nums[i]| >= valueDifference hoga

5. if (it1 != elements.end())
   - Agar aisa element mil gaya, to pair return kar do
   - it1->second humein stored index deta hai

6. auto it2 = elements.lower_bound({nums[i] - valueDifference + 1, -1});
   - Pehla element search karte hain >= (nums[i] - valueDifference + 1)
   - Phir ek step peeche jaake sabse bada element <= (nums[i] - valueDifference) mil jata hai

7. if (it2 != elements.begin()) { --it2; ... }
   - Previous element pe move karte hain (sabse bada value <= nums[i] - valueDifference)
   - Ye ensure karta hai ki |nums[i] - element_value| >= valueDifference

YE KYUN KAAM KARTA HAI:
- Hum valid indices ka sliding window maintain karte hain (distance constraint ke liye)
- Har position i ke liye check karte hain ki koi previous valid element value constraint satisfy karta hai
- Binary search se efficient ho jata hai: O(n log n) instead of O(n²)

EXAMPLE DRY RUN:
Input: nums = [1,2,3], indexDifference = 2, valueDifference = 4

i=2: elements = {(1,0)}, nums[2] = 3
- Value >= 3+4 = 7 search karo: Nahi mila
- Value <= 3-4 = -1 search karo: Nahi mila  
- Continue karo

Koi valid pair exist nahi karta, return [-1, -1]

Input: nums = [5,1,4,1], indexDifference = 2, valueDifference = 4

i=2: elements = {(5,0)}, nums[2] = 4  
- Value >= 4+4 = 8 search karo: Nahi mila
- Value <= 4-4 = 0 search karo: Nahi mila

i=3: elements = {(1,1), (5,0)}, nums[3] = 1
- Value >= 1+4 = 5 search karo: Mil gaya (5,0)
- Return [3, 0] ✓

Verification: |3-0| = 3 >= 2 ✓, |nums[3]-nums[0]| = |1-5| = 4 >= 4 ✓
*/