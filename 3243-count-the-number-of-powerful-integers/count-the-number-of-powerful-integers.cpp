class Solution {
public:
    // dp[idx][tight][started]
    long long dp[20][2][2];
    string s;
    int limit;
    
    long long solve(int idx, bool tight, bool started) {
        // Base case: reached end
        if (idx >= s.size()) {
            // Count all numbers, even if started=false (prefix can be 0)
            return 1;
        }
        
         if (dp[idx][tight][started] != -1) {
            return dp[idx][tight][started];
        }
        
        long long ans = 0;
        int uper_limit = tight ? (s[idx] - '0') : 9;
        
        // Try digits from 0 to min(uper_limit, limit)
        for (int d = 0; d <= min(uper_limit, limit); d++) {
            bool updated_started = started || (d != 0);
            bool updated_tight = tight && (d == uper_limit);
            
            ans += solve(idx + 1, updated_tight, updated_started);
        }
        
         return dp[idx][tight][started] = ans;
    }
    
    long long count_Prefix(long long num) {
        if (num < 0) return 0;
        
        s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return solve(0, true, false);
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suffix) {
        this->limit = limit;
        
        int k = suffix.size();
        long long S = stoll(suffix);  
        
         // If S > finish, no valid numbers idxsible
        if (S > finish) return 0;
        
        // Calculation of 10^k
        long long pow10 = pow(10,k);
        
        
        // Transform problem:
        // Original: start <= prefix*10^k + S <= finish
        // Rearrange: (start-S)/10^k <= prefix <= (finish-S)/10^k
        
        // Lower bound: L = ceil((start - S) / pow10)
        long long L = (start - S + pow10 - 1) / pow10;
        
        // Upper bound: R = floor((finish - S) / pow10)
        long long R = (finish - S) / pow10;
        
        // If no valid prefix range exists
        if (R < L) return 0;
        
        // Additional check: L should be >= 0
        // If L < 0, it means even with prefix=0, number is < start
        // But we need to ensure prefix*10^k + S >= start
        if (L < 0) L = 0;
        
        // Count prefixes in [L, R] where each digit <= limit
        return count_Prefix(R) - count_Prefix(L - 1);
    }
};

