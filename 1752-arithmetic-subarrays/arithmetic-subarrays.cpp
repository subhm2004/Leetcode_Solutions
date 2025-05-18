class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;   

        for (int i = 0; i < m; ++i) {
            int start = l[i];
            int end = r[i];

            vector<int> sub_array;
            for (int idx = start; idx <= end; ++idx) {
                sub_array.push_back(nums[idx]);
            }

            sort(sub_array.begin(), sub_array.end());

            int diff = sub_array[1] - sub_array[0];
            bool is_Arithmetic = true;

            for (int j = 2; j < sub_array.size(); ++j) {
                if (sub_array[j] - sub_array[j - 1] != diff) {
                    is_Arithmetic = false;
                    break;
                }
            }

            ans.push_back(is_Arithmetic);  
        }

        return ans;
    }
};
