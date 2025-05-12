class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        int n = digits.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || i == k) continue;
                    int a = digits[i], b = digits[j], c = digits[k];
                    if (a == 0 || c % 2 != 0) continue; // leading zeros and odd cases
                    int num = a * 100 + b * 10 + c;
                    ans.insert(num);
                }
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
