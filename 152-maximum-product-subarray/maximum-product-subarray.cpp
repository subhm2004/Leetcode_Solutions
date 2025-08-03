// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxProd = nums[0];  // Final max product store karega
//         int maxSoFar = nums[0]; // Current position tak ka max product
//         int minSoFar = nums[0]; // Current position tak ka min product (negative values handle karne ke liye)

//         for (int i = 1; i < n; i++) {
//             if (nums[i] < 0) swap(maxSoFar, minSoFar);  // Agar negative number aaya toh max aur min ko swap karna padega

//             maxSoFar = max(nums[i], maxSoFar * nums[i]); // Current index pe max product nikalna
//             minSoFar = min(nums[i], minSoFar * nums[i]); // Current index pe min product nikalna (negative ka effect dekhne ke liye)

//             maxProd = max(maxProd, maxSoFar); // Global max product update karna
//         }

//         return maxProd; // Final maximum product return karna
//     }
// };
class Solution {
public:
    vector<vector<int>> dp; // Memoization ke liye DP array

    // Helper function jo recursion aur memoization ka use karke max aur min product nikalta hai
    int helper(vector<int>& nums, int i, bool isMax) {
        if (i < 0) return isMax ? INT_MIN : INT_MAX; // Base case: Agar index out of bound ho gaya

        if (dp[isMax][i] != INT_MAX) return dp[isMax][i]; // Agar pehle se calculate hai toh return kar do

        int curr = nums[i]; // Current element
        int maxProd = curr, minProd = curr; // Maximum aur minimum product initialize karna

        if (i > 0) { // Agar index 0 se bada hai toh previous elements ka product consider karenge
            int prevMax = helper(nums, i - 1, true);  // Pehle ka max product
            int prevMin = helper(nums, i - 1, false); // Pehle ka min product

            // Maximum aur minimum product calculate karna (negative values handle karne ke liye)
            maxProd = max(curr, max(curr * prevMax, curr * prevMin));
            minProd = min(curr, min(curr * prevMax, curr * prevMin));
        }

        dp[true][i] = maxProd;  // DP me max product store karna
        dp[false][i] = minProd; // DP me min product store karna

        return isMax ? maxProd : minProd; // Agar max chahiye toh maxProd return hoga warna minProd
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(2, vector<int>(n, INT_MAX)); // DP table initialize karna
        int result = INT_MIN;

        for (int i = 0; i < n; ++i) {
            result = max(result, helper(nums, i, true)); // Har index ke liye max product calculate karna
        }

        return result; // Final maximum product return karna
    }
};
