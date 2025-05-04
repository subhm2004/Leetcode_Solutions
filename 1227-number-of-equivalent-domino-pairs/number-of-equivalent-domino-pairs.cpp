// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         int count = 0;
//         int n = dominoes.size();
        
//         for (int i = 0; i < n; ++i) {
//             int a = dominoes[i][0];
//             int b = dominoes[i][1];
//             for (int j = i + 1; j < n; ++j) {
//                 int c = dominoes[j][0];
//                 int d = dominoes[j][1];
//                 if ((a == c && b == d) || (a == d && b == c)) {
//                     count++;
//                 }
//             }
//         }
        
//         return count;
//     }
// };
class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<pair<int, int>, int, hash_pair> freq;
        int count = 0;

        for (const auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            freq[{a, b}]++;
        }

        for (const auto& [p, val] : freq) {
            if (val > 1) {
                count += (val * (val - 1)) / 2; // nC2
            }
        }

        return count;
    }
};

