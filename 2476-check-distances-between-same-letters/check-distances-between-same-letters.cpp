class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> first_occ(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';

            if (first_occ[ch] == -1) {
                first_occ[ch] = i;
            } else {
                int gap = i - first_occ[ch] - 1;
                if (gap != distance[ch])
                    return false;
            }
        }
        return true;
    }
};