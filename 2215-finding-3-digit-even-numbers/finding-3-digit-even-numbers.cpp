class Solution {
public:
    void solve(int current, int k, vector<int>& freq, vector<int>& ans) {
        if (k == 0) {
            if (current % 2 == 0) 
                ans.push_back(current);
            return;
        }
        current = current * 10;
        for (int i = 0; i <= 9; i++) {
            if (current == 0 && i == 0) 
                continue;
            if (freq[i] > 0) {
                freq[i]--;
                solve(current + i, k - 1, freq, ans);
                freq[i]++;
            }
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> freq(10, 0);
        for (auto d : digits) 
            freq[d]++;  // Count the frequency of each digit in the input

        solve(0, 3, freq, ans);  // Start solving for 3-digit numbers
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int>& digits) {
//         set<int> ans;
//         int n = digits.size();
        
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 for (int k = 0; k < n; ++k) {
//                     if (i == j || j == k || i == k) continue;
//                     int a = digits[i], b = digits[j], c = digits[k];
//                     if (a == 0 || c % 2 != 0) continue; // leading zeros and odd cases
//                     int num = a * 100 + b * 10 + c;
//                     ans.insert(num);
//                 }
//             }
//         }
        
//         return vector<int>(ans.begin(), ans.end());
//     }
// };
