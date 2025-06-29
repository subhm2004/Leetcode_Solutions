class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> ans;
        int n = s.size();

        int i = 0;

        while (i < n) {
            int j = i;
            while (j < n) {
                string sub = s.substr(i, j - i + 1);  // substring from i to j
                if (seen.find(sub) == seen.end()) {
                    ans.push_back(sub);
                    seen.insert(sub);
                    break;
                }
                j++;
            }
            i = j + 1;
        }

        return ans;
    }
};
