// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<string> num;
//         for (int i = 1; i <= n; i++) {
//             num.push_back(to_string(i));
//         }
//         sort(num.begin(), num.end());
//         vector<int> ans;
//         for ( auto& nums : num) {
//             ans.push_back(stoi(nums));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void solveRE(int curr, int n, vector<int>& ans) {
        if (curr > n)
            return;

        ans.push_back(curr);

        for (int next_Digit = 0; next_Digit <= 9; next_Digit++) {
            int next_num = curr * 10 + next_Digit;

            if (next_num > n)
                return;

            solveRE(next_num, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for (int num = 1; num <= 9; num++)
            solveRE(num, n, ans);

        return ans;
    }
};
