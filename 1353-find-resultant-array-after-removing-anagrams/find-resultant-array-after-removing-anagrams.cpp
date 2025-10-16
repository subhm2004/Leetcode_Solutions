class Solution {
public:
    //     bool is_anagram(const string& a, const string& b) {
    //     if (a.length() != b.length()) {
    //         return false;
    //     }
        
    //     vector<int> count(26, 0);
        
    //     for (const char c : a) {
    //         ++count[c - 'a'];
    //     }
        
    //     for (const char c : b) {
    //         --count[c - 'a'];
    //     }
        
    //     for (const int c : count) {
    //         if (c != 0) {
    //             return false;
    //         }
    //     }
        
    //     return true;
    // }
    bool is_anagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        if (words.empty()) {
            return ans;
        }

        for (int i = 0; i < words.size();) {
            int j = i + 1;
            while (j < words.size() && is_anagram(words[i], words[j])) {
                ++j;
            }
            ans.push_back(words[i]);
            i = j;
        }
        return ans;
    }
};
