class Solution {    // Moore Voting Algorithm 
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate_1 = 0, candidate_2 = 1;
        int count_1 = 0, count_2 = 0;
        int n = nums.size();

        // First pass: find potential candidates
        for (int i = 0; i < n; ++i) {
            if (nums[i] == candidate_1) {
                count_1++;
            } else if (nums[i] == candidate_2) {
                count_2++;
            } else if (count_1 == 0) {
                candidate_1 = nums[i];
                count_1 = 1;
                continue;
            } else if (count_2 == 0) {
                candidate_2 = nums[i];
                count_2 = 1;
                continue;
            } else {
                count_1--;
                count_2--;
            }
        }

        // Second pass: verify candidates
        count_1 = 0;
        count_2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == candidate_1) {
                count_1++;
            } else if (nums[i] == candidate_2) {
                count_2++;
            }
        }

        vector<int> ans;
        if (count_1 > n / 3) ans.push_back(candidate_1);
        if (count_2 > n / 3) ans.push_back(candidate_2);

        return ans;
    }
};

