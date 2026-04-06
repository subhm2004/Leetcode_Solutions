class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;

        // count frequency
        for (char c : s) {
            freq[c]++;
        }

        unordered_set<char> visited;
        int ans = 0;

        for (auto &it : freq) {
            char c = it.first;

            if (visited.count(c)) continue;

            char m;

            // find mirror
            if (isdigit(c)) {
                m = '9' - (c - '0');
            } else {
                m = 'z' - (c - 'a');
            }

            int f1 = freq[c];
            int f2 = freq.count(m) ? freq[m] : 0;

            ans += abs(f1 - f2);

            // mark both as visited
            visited.insert(c);
            visited.insert(m);
        }

        return ans;
    }
};