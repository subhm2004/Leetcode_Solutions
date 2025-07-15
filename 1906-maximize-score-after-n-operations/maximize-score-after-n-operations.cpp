//  vector<int> ke liye custom hash function 
    struct Vector_Hash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int num : v) {
            hash = hash * 31 + num;
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<int>> gcd_table;
    unordered_map<vector<int>, int, Vector_Hash> dp;

    int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    void precompute_GCD(vector<int>& nums) {
        int n = nums.size();
        gcd_table.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int g = GCD(nums[i], nums[j]);
                gcd_table[i][j] = gcd_table[j][i] = g;
            }
        }
    }

    int backtrack(vector<int>& arr, int operation) {
        if (arr.size() < 2) return 0;

        if (dp.count(arr)) return dp[arr];

        int max_score = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> next_arr;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        next_arr.push_back(arr[k]);
                }

                int score = operation * gcd_table[arr[i]][arr[j]];
                score += backtrack(next_arr, operation + 1);

                max_score = max(max_score, score);
            }
        }

        return dp[arr] = max_score;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        precompute_GCD(nums);

        vector<int> arr; 
        for (int i = 0; i < n; ++i)
            arr.push_back(i);

        return backtrack(arr, 1);
    }
};
