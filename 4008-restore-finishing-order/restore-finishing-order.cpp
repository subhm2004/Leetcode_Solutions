class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;

        for (int id : order) {
            // check manually if id is in friends
            for (int f : friends) {
                if (id == f) {
                    ans.push_back(id);
                    break; // match mil gaya, aage check karne ki zarurat nahi
                }
            }
        }
        return ans;
    }
};