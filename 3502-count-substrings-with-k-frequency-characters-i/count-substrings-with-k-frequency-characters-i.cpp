class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                bool valid = false;

                for (auto f : freq) {
                    if (f.second >= k) {
                        valid = true;
                        break;
                    }
                }
                if (valid) {
                    total += (n - j);
                    break;
                }
            }
        }
        return total;
    }
};