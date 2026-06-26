class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        if (sum > 9 * num) {
            return "";
        }
        
        vector<int> digits(num, 0);
        
        int remaining = sum;
        
        for (int i = 0; i < num && remaining > 0; i++) {
            int d = min(9, remaining);
            digits[i] = d;
            remaining -= d;
        }
        
  
        if (remaining > 0) {
            return "";
        }
        
     
        string ans = "";
        for (int d : digits) {
            ans += to_string(d);
        }
        
        return ans;
    }
};