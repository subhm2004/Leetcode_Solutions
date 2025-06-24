// class Solution {     // Brute Force Approach 2008/2013
// public:
//     int minAbsoluteDifference(vector<int>& nums, int x) {
//         int n = nums.size();
//         int ans = INT_MAX;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (abs(i - j) >= x) {
//                     ans = min(ans, abs(nums[i] - nums[j]));
//                 }
//             }
//         }
//         return ans;
//     }
// };

//---------------------------------------------------------------------------------------------------------
/*
Input: nums = [5,3,2,10,15], x = 1
Array indices:  0 1 2  3  4
Array values:   5 3 2 10 15

Constraint: |i-j| >= x (distance between indices >= 1)
Goal: Find minimum |nums[i] - nums[j]| where |i-j| >= 1
*/

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();        // n = 5
        int ans = INT_MAX;          // ans = infinity (largest possible value)
        
        // Set to store valid elements (automatically sorted)
        set<int> validElements;     // Initially empty: {}
        
        // Loop through array starting from index x
        // Why x? Because we need distance >= x, so we start from x
        // to ensure we have at least one valid element to compare with
        for (int i = x; i < n; ++i) {  // i starts from 1, goes till 4
            
            // Add element that is exactly x distance away
            // nums[i-x] is at distance x from current position i
            // Distance = |i - (i-x)| = |i - i + x| = x ✓
            validElements.insert(nums[i - x]);
            
            // Binary search: find closest element to nums[i]
            // lower_bound returns iterator to first element >= nums[i]
            auto it = validElements.lower_bound(nums[i]);
            
            // Check element just >= nums[i] (ceiling)
            if (it != validElements.end()) {
                // *it is the smallest element >= nums[i]
                ans = min(ans, abs(nums[i] - *it));
            }
            
            // Check element just < nums[i] (floor)
            if (it != validElements.begin()) {
                it--;  // Move to previous element (largest element < nums[i])
                ans = min(ans, abs(nums[i] - *it));
            }
        }
        
        return ans;
    }
};

/*
DRY RUN:
Input: nums = [5,3,2,10,15], x = 1

Initial state:
- n = 5
- ans = INT_MAX
- validElements = {} (empty set)

ITERATION 1: i = 1
- nums[i] = nums[1] = 3
- validElements.insert(nums[i-x]) = insert(nums[0]) = insert(5)
- validElements = {5}
- lower_bound(3) on {5} returns iterator to 5 (first element >= 3)
- it points to 5
- Check >= nums[i]: |3 - 5| = 2, ans = min(INT_MAX, 2) = 2
- Check < nums[i]: it == begin(), so no element < 3
- ans = 2

ITERATION 2: i = 2  
- nums[i] = nums[2] = 2
- validElements.insert(nums[i-x]) = insert(nums[1]) = insert(3)
- validElements = {3, 5} (automatically sorted)
- lower_bound(2) on {3,5} returns iterator to 3 (first element >= 2)
- it points to 3
- Check >= nums[i]: |2 - 3| = 1, ans = min(2, 1) = 1
- Check < nums[i]: it == begin(), so no element < 2  
- ans = 1

ITERATION 3: i = 3
- nums[i] = nums[3] = 10
- validElements.insert(nums[i-x]) = insert(nums[2]) = insert(2)
- validElements = {2, 3, 5}
- lower_bound(10) on {2,3,5} returns iterator to end() (no element >= 10)
- it points to end()
- Check >= nums[i]: it == end(), so skip
- Check < nums[i]: it != begin(), so it-- points to 5
- |10 - 5| = 5, ans = min(1, 5) = 1
- ans = 1

ITERATION 4: i = 4
- nums[i] = nums[4] = 15  
- validElements.insert(nums[i-x]) = insert(nums[3]) = insert(10)
- validElements = {2, 3, 5, 10}
- lower_bound(15) on {2,3,5,10} returns iterator to end()
- it points to end()
- Check >= nums[i]: it == end(), so skip
- Check < nums[i]: it != begin(), so it-- points to 10
- |15 - 10| = 5, ans = min(1, 5) = 1
- ans = 1

Final Answer: 1

Verification: The minimum absolute difference with distance >= 1 is:
|nums[1] - nums[2]| = |3 - 2| = 1, where |1-2| = 1 >= x ✓
*/