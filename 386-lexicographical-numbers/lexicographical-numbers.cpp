class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> num;
        for (int i = 1; i <= n; i++) {
            num.push_back(to_string(i));
        }
        sort(num.begin(), num.end());
        vector<int> ans;
        for ( auto& nums : num) {
            ans.push_back(stoi(nums));
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<int> ans;
//         int curr = 1;
//         for (int i = 0; i < n; i++) {
//             ans.push_back(curr);
//             if (curr * 10 <= n) {
//                 curr *= 10;  // Move to the next depth
//             } else {
//                 while (curr % 10 == 9 || curr + 1 > n) {
//                     curr /= 10;  // Backtrack if last digit is 9 or exceeds n
//                 }
//                 curr++;  // Move to next number
//             }
//         }
//         return ans;
//     }
// };
