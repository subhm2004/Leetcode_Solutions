class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix_max(n); //prefix_max[i] = max element from index 0 to i
        vector<int> suffix_min(n); //suffix_min[i] = min element from i+1 to n

        prefix_max[0] = nums[0];
        suffix_min[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {
            prefix_max[i] = max(nums[i], prefix_max[i-1]);
        }

        for(int i = n-2; i >= 0; i--) {
            suffix_min[i] = min(nums[i], suffix_min[i+1]);
        }

        vector<int> ans(n);

        ans[n-1] = prefix_max[n-1];

        for(int i = n-2; i >= 0; i--) {
            if(prefix_max[i] <= suffix_min[i+1]) { //can't go to right at all
                ans[i] = prefix_max[i];
            } else {
                ans[i] = ans[i+1];
            }
        }

        return ans;
    }
};

