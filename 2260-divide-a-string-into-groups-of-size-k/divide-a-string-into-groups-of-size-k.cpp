/*
Divide string s into groups of size k.

Each group must be of exactly size k.

If the last group has less than k characters, you should add the fill character at the end to make its size exactly k.


*/
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        
        for (int i = 0; i < n; i += k) {
            string group = s.substr(i, k);
            // If group is shorter than k, pad it with fill characters
            while (group.size() < k) {
                group += fill;
            }
            ans.push_back(group);
        }

        return ans;
    }
};
