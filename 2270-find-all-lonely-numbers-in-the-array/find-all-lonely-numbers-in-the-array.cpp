class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        unordered_map<int,int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<int> ans;

        // check lonely
        for (int i = 0; i < nums.size(); i++) {

            int x = nums[i];

            if (freq[x] == 1 && freq.count(x - 1) == 0 && freq.count(x + 1) == 0)
            {
                ans.push_back(x);
            }
        }

        return ans;
    }
};
