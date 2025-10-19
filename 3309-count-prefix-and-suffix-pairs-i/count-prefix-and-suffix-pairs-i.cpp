class Solution {
public:
    bool is_prefix_and_is_suffix(const string& str1, const string& str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        if (len1 > len2)
            return false; // str1 badi ho, impossible
        bool is_prefix = (str1 == str2.substr(0, len1));
        bool is_suffix = (str1 == str2.substr(len2 - len1, len1));
        return is_prefix && is_suffix;
    }

    int countPrefixSuffixPairs(const vector<string>& words) {
        int n = words.size();
        if (all_of(words.begin(), words.end(), [&](const string& s){ return s == words[0]; })) {
        return  n * (n - 1) / 2;
    }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (is_prefix_and_is_suffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};