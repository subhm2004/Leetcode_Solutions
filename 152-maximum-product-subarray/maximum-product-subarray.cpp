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

