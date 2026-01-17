class Solution {
public:
    // dp[idx][sum][tight][started]
    // idx: current postiton
    // sum: current digit sum
    // tight: are we still bounded by limit
    // started: have we placed a non-zero digit
    int dp[6][46][2][2];
    string s;
    int target_sum;
    
    int solve(int idx, int sum, bool tight, bool started) {
        // Pruning: if sum already exceeds target, no point continuing
        if (sum > target_sum) return 0;
        
        // Base case: reached end of number
        if (idx == s.size()) {
            // Count this number only if we started and sum matches target
            return (started && sum == target_sum) ? 1 : 0;
        }
        
        // Check memoization
        if (dp[idx][sum][tight][started] != -1) {
            return dp[idx][sum][tight][started];
        }
        
        int ans = 0;
        int limit = tight ? (s[idx] - '0') : 9;
        
        // Try all possible digits
        for (int d = 0; d <= limit; d++) {
            bool updated_started = started || (d != 0);
            bool updated_tight = tight && (d == limit);
            int updated_sum = sum + (updated_started ? d : 0);
            
            ans += solve(idx + 1, updated_sum, updated_tight, updated_started);
        }
        
        return dp[idx][sum][tight][started] = ans;
    }
    
    // Count numbers in range [0, num] with digit sum = target
    int count_with_digit_sum(int num, int target) {
        if (num < 0) return 0;
        
        s = to_string(num);
        target_sum = target;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, true, false);
    }
    
    int countBalls(int low_limit, int high_limit) {
        int max_balls = 0;
        
        // For high_limit = 100000, max digit sum = 1+0+0+0+0+0 = 1
        // But for 99999, max digit sum = 9*5 = 45
        // So we check all idxsible digit sums from 1 to 45
        
        for (int digit_sum = 1; digit_sum <= 45; digit_sum++) {
            // Count numbers with this digit sum in [low_limit, high_limit]
            int count_high = count_with_digit_sum(high_limit, digit_sum);
            int count_low = count_with_digit_sum(low_limit - 1, digit_sum);
            
            int balls_in_box = count_high - count_low;
            max_balls = max(max_balls, balls_in_box);
        }
        
        return max_balls;
    }
};