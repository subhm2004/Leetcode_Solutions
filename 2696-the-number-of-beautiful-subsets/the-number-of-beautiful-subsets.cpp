class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Iterate through all subsets using bitmask
        for (int mask = 1; mask < (1 << n);
             mask++) { // mask = 0 is empty subset
            bool beautiful = true;
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    subset.push_back(nums[i]);
            }

            // Check if subset is beautiful
            for (int i = 0; i < subset.size(); i++) {
                for (int j = i + 1; j < subset.size(); j++) {
                    if (abs(subset[i] - subset[j]) == k) {
                        beautiful = false;
                        break;
                    }
                }
                if (!beautiful)
                    break;
            }

            if (beautiful)
                count++;
        }

        return count;
    }
};