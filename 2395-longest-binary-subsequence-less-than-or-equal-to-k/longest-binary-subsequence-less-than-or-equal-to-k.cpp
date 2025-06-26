class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length = 0;
        long long power_Value = 1;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                length++;
            } else if(power_Value <= k) {
                length++;
                k = k - power_Value;
            }

            if (power_Value <= k)
                power_Value <<= 1; //power_Value *= 2;
        }
        
        return length;
    }
};




//-----------------------------------------------------------------------------------------------------------
// class Solution {          // MLE aayega isme values bohot badi h code ki 
// public:
//     int n;
//     vector<vector<int>> dp;
    
//     int solveRE(const string &s, int k, int i) {
//         if (i < 0) return 0;

//         int take = 0;
//         int bit = s[i] - '0';
//         long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);

//         if (value <= k) {
//             take = 1 + solveRE(s, k - value, i - 1);
//         }

//         int skip = solveRE(s, k, i - 1);
//         return max(take, skip);
//     }

//     int solveME(const string &s, int k, int i) {
//         if (i < 0) return 0;
//         if (dp[i][k] != -1) return dp[i][k];

//         int take = 0;
//         int bit = s[i] - '0';
//         long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);

//         if (value <= k) {
//             take = 1 + solveME(s, k - value, i - 1);
//         }

//         int skip = solveME(s, k, i - 1);
//         return dp[i][k] = max(take, skip);
//     }

//     int longestSubsequence(string &s, int k) {
//         n = s.length();
//         dp.assign(n, vector<int>(k + 1, -1));

//         return solveME(s, k, n - 1);
//     }
// };


