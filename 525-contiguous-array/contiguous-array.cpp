class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefix_sum_map;
        int curr_sum = 0, max_len = 0;

        prefix_sum_map[0] = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                curr_sum -= 1;
            else
                curr_sum += 1;

            if (prefix_sum_map.count(curr_sum))
                max_len = max(max_len, i - prefix_sum_map[curr_sum]);
            else
                prefix_sum_map[curr_sum] = i;
        }

        return max_len;
    }
};