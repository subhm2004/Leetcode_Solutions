class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> ans;

        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            groups[size].push_back(i);

            if (groups[size].size() == size) {
                ans.push_back(groups[size]);
                
                groups[size].clear();  // clear the group for next batch
            }
        }

        return ans;
    }
};
