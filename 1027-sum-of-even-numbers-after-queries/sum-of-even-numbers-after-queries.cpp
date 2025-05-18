class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto &q : queries) {
            int val = q[0];
            int i = q[1];

            // Update nums
            nums[i] += val;

            // Calculate sum of even numbers after update
            int sum_Even = 0;
            for (int num : nums) {
                if (num % 2 == 0)
                    sum_Even += num;
            }

            ans.push_back(sum_Even);
        }

        return ans;
    }
};
