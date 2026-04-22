class Solution {
public:
    bool can_match(string &a, string &b) {
        int diff = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for (string &query : queries) {
            for (string &word : dictionary) {
                if (can_match(query, word)) {
                    ans.push_back(query);
                    break; // ek match mil gaya to next query
                }
            }
        }

        return ans;
    }
};