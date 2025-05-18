class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;  // yahan hum har query ke baad ka answer store karenge

        for (auto &q : queries) {
            int val = q[0];
            int idx = q[1];

            nums[idx] += val;  // update kar diya

            // Ab sum calculate karte hain sirf even numbers ka
            int sum = 0;
            for (int num : nums) {
                if (num % 2 == 0)
                    sum += num;
            }

            ans.push_back(sum);  // answer ans me daal diya
        }

        return ans;  // sab answers wapas kar do
    }
};
