// SOLUTION 1: OPTIMIZED DYNAMIC PROGRAMMING APPROACH (Kadane's Algorithm Modified)
// Time Complexity: O(n), Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        // Global maximum product jo final answer hoga
        int maxProd = nums[0];
        
        // Current position tak ka maximum product store karta hai
        // Ye track karta hai ki current element ko include karke maximum kya mil sakta hai
        int maxSoFar = nums[0];
        
        // Current position tak ka minimum product store karta hai
        // Ye isliye zaroori hai kyunki negative number * negative number = positive
        // Toh agar current element negative hai aur pehle ka minimum bhi negative hai,
        // toh unka product maximum ho sakta hai
        int minSoFar = nums[0];
        
        // Array ke second element se start karte hain
        for (int i = 1; i < n; i++) {
            
            // CRITICAL STEP: Agar current element negative hai
            // Toh maxSoFar aur minSoFar ko swap karna padega
            // Kyunki: negative * maximum = minimum, negative * minimum = maximum
            if (nums[i] < 0) {
                swap(maxSoFar, minSoFar);
            }
            
            // Current index pe maximum product calculate karna
            // Ya toh current element khud maximum hai
            // Ya fir current element * previous maximum product
            maxSoFar = max(nums[i], maxSoFar * nums[i]);
            
            // Current index pe minimum product calculate karna
            // Ye negative numbers ke case me future maximum banne ke liye important hai
            minSoFar = min(nums[i], minSoFar * nums[i]);
            
            // Global maximum ko update karna
            // Har step me check karte hain ki current maximum global maximum se bada hai ya nahi
            maxProd = max(maxProd, maxSoFar);
        }
        
        return maxProd; // Final maximum product return karna
    }
};

// SOLUTION 2: RECURSIVE APPROACH WITH MEMOIZATION
// Time Complexity: O(n), Space Complexity: O(n)

// class Solution {
// public:
//     // 2D DP array for memoization
//     // dp[0][i] = minimum product ending at index i
//     // dp[1][i] = maximum product ending at index i
//     vector<vector<int>> dp;
    
//     // Recursive helper function jo memoization use karta hai
//     // nums: input array
//     // i: current index
//     // isMax: true matlab maximum product chahiye, false matlab minimum
//     int helper(vector<int>& nums, int i, bool isMax) {
        
//         // Base case: Agar index negative ho gaya (out of bounds)
//         if (i < 0) {
//             // Maximum ke liye INT_MIN return karte hain (smallest possible value)
//             // Minimum ke liye INT_MAX return karte hain (largest possible value)
//             return isMax ? INT_MIN : INT_MAX;
//         }
        
//         // Memoization check: Agar ye state pehle calculate ho chuki hai
//         if (dp[isMax][i] != INT_MAX) {
//             return dp[isMax][i]; // Stored value return kar do
//         }
        
//         int curr = nums[i]; // Current element
//         int maxProd = curr; // Current element se maximum product (initially current element khud)
//         int minProd = curr; // Current element se minimum product (initially current element khud)
        
//         // Agar current index 0 se bada hai (matlab previous elements exist karte hain)
//         if (i > 0) {
//             // Previous index tak ka maximum product nikalna (recursive call)
//             int prevMax = helper(nums, i - 1, true);
            
//             // Previous index tak ka minimum product nikalna (recursive call)
//             int prevMin = helper(nums, i - 1, false);
            
//             // Current index pe maximum product calculate karna
//             // Teen options hain:
//             // 1. Sirf current element
//             // 2. Current element * previous maximum
//             // 3. Current element * previous minimum (agar current negative hai toh ye maximum de sakta hai)
//             maxProd = max(curr, max(curr * prevMax, curr * prevMin));
            
//             // Current index pe minimum product calculate karna
//             // Teen options hain:
//             // 1. Sirf current element
//             // 2. Current element * previous maximum (agar current negative hai toh ye minimum de sakta hai)
//             // 3. Current element * previous minimum
//             minProd = min(curr, min(curr * prevMax, curr * prevMin));
//         }
        
//         // Calculated values ko DP table me store karna (memoization)
//         dp[true][i] = maxProd;   // Maximum product store karna
//         dp[false][i] = minProd;  // Minimum product store karna
        
//         // Caller ne jo manga hai wo return karna (max ya min)
//         return isMax ? maxProd : minProd;
//     }
    
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
        
//         // DP table initialize karna
//         // 2 rows (max aur min ke liye), n columns (har index ke liye)
//         // INT_MAX se initialize karte hain taaki pata chal sake ki calculate nahi hua hai
//         dp = vector<vector<int>>(2, vector<int>(n, INT_MAX));
        
//         int result = INT_MIN; // Final result initialize karna
        
//         // Har possible ending position ke liye maximum product calculate karna
//         for (int i = 0; i < n; ++i) {
//             // Index i pe ending hone wala maximum product nikalna
//             int currentMax = helper(nums, i, true);
            
//             // Global maximum update karna
//             result = max(result, currentMax);
//         }
        
//         return result; // Final maximum product return karna
//     }
// };

// /*
// KEY DIFFERENCES BETWEEN BOTH APPROACHES:

// 1. APPROACH 1 (Iterative DP):
//    - More space efficient (O(1) space)
//    - Faster execution due to no function call overhead
//    - Uses modified Kadane's algorithm concept
//    - Handles negative numbers by swapping max and min

// 2. APPROACH 2 (Recursive with Memoization):
//    - Uses more space (O(n) for recursion stack + DP table)
//    - More intuitive to understand for some people
//    - Calculates subproblems on demand
//    - Explicitly handles all cases in recursive manner

// EXAMPLE WALKTHROUGH for nums = [2, 3, -2, 4]:

// Approach 1:
// i=0: maxSoFar=2, minSoFar=2, maxProd=2
// i=1: maxSoFar=6, minSoFar=3, maxProd=6
// i=2: swap (negative), maxSoFar=-2, minSoFar=-18, maxProd=6
// i=3: maxSoFar=4, minSoFar=-72, maxProd=6

// Approach 2:
// Calculates for each ending position and finds global maximum = 6
// */