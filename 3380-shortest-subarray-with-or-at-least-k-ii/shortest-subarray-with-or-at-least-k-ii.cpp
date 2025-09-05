class Solution {
public:
    // Function: bit count array ko update karta hai
    // num ke har set bit ko bitCount array mein add/subtract karta hai
    void update_bit_count(vector<int>& bitCount, int num, int delta) {
        // 0 se 31 tak har bit position check karte hain (32-bit integers ke liye)
        for (int i = 0; i < 32; i++) {
            // Agar num ka i-th bit set hai (1 hai)
            if (num & (1 << i)) {
                // toh bitCount[i] mein delta add kar do
                // delta = +1 (element add karte time), delta = -1 (element remove karte time)
                bitCount[i] += delta;
            }
        }
    }
    
    // Function: bit count array se actual OR value calculate karta hai
    int get_OR_from_bit_count(vector<int>& bitCount) {
        int result = 0;  // Result initialize karo 0 se
        
        // Har bit position check karo
        for (int i = 0; i < 32; i++) {
            // Agar i-th position pe koi bhi element ka bit set hai (count > 0)
            if (bitCount[i] > 0) {
                // toh result mein i-th bit ko set kar do
                result |= (1 << i);
            }
        }
        return result;  // Final OR value return karo
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();           // Array ka size
        int min_len = INT_MAX;         // Minimum length track karne ke liye
        
        // Bit count array - har position pe kitne elements ka bit set hai
        // Index 0 = 0th bit, Index 1 = 1st bit, etc.
        vector<int> bitCount(32, 0);
        
        int left = 0;  // Sliding window ka left pointer
        
        // Right pointer ko 0 se n-1 tak move karte hain
        for (int right = 0; right < n; right++) {
            // Current element (nums[right]) ko window mein add karo
            // +1 delta means add kar rahe hain
            update_bit_count(bitCount, nums[right], 1);
            
            // Jab tak window ka OR >= k hai, window ko shrink karte raho
            while (left <= right && get_OR_from_bit_count(bitCount) >= k) {
                // Current window length calculate karo aur minimum update karo
                min_len = min(min_len, right - left + 1);
                
                // Left element ko window se remove karo
                // -1 delta means remove kar rahe hain
                update_bit_count(bitCount, nums[left], -1);
                
                // Left pointer ko aage move karo (window shrink)
                left++;
            }
        }
        
        // Agar koi valid subarray nahi mila toh -1 return karo
        // Otherwise minimum length return karo
        return min_len == INT_MAX ? -1 : min_len;
    }
};

/*
ALGORITHM KA LOGIC (Hinglish mein):

1. SLIDING WINDOW TECHNIQUE:
   - Do pointers use karte hain: left aur right
   - Right pointer expand karta hai window ko
   - Left pointer shrink karta hai window ko

2. BIT COUNTING APPROACH:
   - 32-size ka array maintain karte hain (bitCount)
   - bitCount[i] = current window mein kitne numbers ka i-th bit set hai
   - Jab element add karte hain: bit counts increase karte hain
   - Jab element remove karte hain: bit counts decrease karte hain

3. OR CALCULATION:
   - Window ka OR = jo bhi bit positions pe count > 0 hai, woh set karo
   - Efficient hai kyunki har baar full OR recalculate nahi karna padta

4. WINDOW MANAGEMENT:
   - Right move karo aur element add karo
   - Jab OR >= k ho jaye, window shrink karo left se
   - Har valid window ka length track karo

TIME COMPLEXITY: O(n * 32) = O(n) - because bit operations are constant
SPACE COMPLEXITY: O(1) - only 32-size array

EXAMPLE: nums = [2,1,8], k = 10
- k = 10 (binary: 1010, bits 1 and 3 set hone chahiye)
- Window [2,1,8]: OR = 11 (binary: 1011) >= 10 ✓
- Length = 3
*/