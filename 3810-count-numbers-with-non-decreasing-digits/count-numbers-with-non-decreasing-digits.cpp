class Solution {
public:
    int MOD = 1e9 + 7;
    int base;
    // 100*log2(10) aayega kuch 332 so 350 is safe size
    int dp[350][11][2][2]; // dp[idx][prev_digit+1][tight][started]
    string s;
    
   string convert_to_base_b(string num, int b) {
    string base_b_str = "";  // Final answer store hoga (reverse mein)
    
    while (true) {  // Jab tak division khatam nahi hota
        int remainder = 0;
        string next_num = "";  // Quotient store hoga
        
        // Long division: num ko b se divide karo
        for (char c : num) {
            int current = remainder * 10 + (c - '0');
            // Pehle digit ko process karte hain, baaki remainder next ke liye
            
            int digit = current / b;    // Quotient ka digit
            remainder = current % b;    // Remainder next step ke liye
            
            // Leading zeros skip karo quotient mein
            if (!(next_num.empty() && digit == 0)) {
                next_num.push_back('0' + digit);
            }
        }
        
        // Last remainder base-b ka ek digit hai
        base_b_str.push_back('0' + remainder);
        
        // Agar quotient 0 ho gaya, khatam!
        if (next_num.empty()) break;
        
        num = next_num;  // Next iteration ke liye quotient use karo
    }
    
    // Remainders ulta order mein store hue, so reverse karo
    reverse(base_b_str.begin(), base_b_str.end());
    return base_b_str;
}

    int solve(int idx, int prev_digit, bool tight, bool started) {
        if (idx == s.size()) {
            return started ? 1 : 0;
        }
        
        int pd = prev_digit + 1;  
        
        if (dp[idx][pd][tight][started] != -1) {
            return dp[idx][pd][tight][started];
        }
        
        long long ans = 0;
        int limit = tight ? (s[idx] - '0') : (base - 1);
        
        for (int d = 0; d <= limit; d++) {
            bool updated_started = started || (d != 0);
            bool updated_tight = tight && (d == limit);
            
            // Check karte hai non-decreasing condition
            if (updated_started) {
                if (prev_digit != -1 && d < prev_digit) {
                    continue; // Skip kro decreasing hai
                }
            }
            
            int new_prev_digit = updated_started ? d : -1;
            ans = (ans + solve(idx + 1, new_prev_digit, updated_tight, updated_started)) % MOD;
        }
        
        return dp[idx][pd][tight][started] = ans;
    }
    
    int count_non_decreasing(string num) {
        // Convert num to base b using conversion
        s = convert_to_base_b(num, base);
        
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, true, false);
    }
    
    void subtract_minus_one(string &x) {
        int i = x.size() - 1;
        while (i >= 0 && x[i] == '0') {
            x[i] = '9';
            i--;
        }
        if (i >= 0) x[i]--;
    }
    
    int countNumbers (string l, string r, int b) {
        base = b;
        
        long long count_R = count_non_decreasing(r);
        
        subtract_minus_one(l);
    
        
        long long count_L = (l == "0") ? 0 : count_non_decreasing(l);
        
        long long ans = (count_R - count_L + MOD) % MOD;
        return ans;
    }
};

/*

# Detailed Example: "23" → base 8

### **Iteration 1:**
```
num = "23"
remainder = 0

Process '2':
  current = 0*10 + 2 = 2
  digit = 2/8 = 0  (skip, leading zero)
  remainder = 2%8 = 2

Process '3':
  current = 2*10 + 3 = 23
  digit = 23/8 = 2
  remainder = 23%8 = 7
  next_num = "2"

base_b_str = "7"
num = "2" (next iteration ke liye)
```

### **Iteration 2:**
```
num = "2"
remainder = 0

Process '2':
  current = 0*10 + 2 = 2
  digit = 2/8 = 0  (skip)
  remainder = 2%8 = 2
  next_num = "" (empty!)

base_b_str = "72"
next_num empty hai, so BREAK!


base_b_str = "72"
Reverse → "27" ans hai 

*/