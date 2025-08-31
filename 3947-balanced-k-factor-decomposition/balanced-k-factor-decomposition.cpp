class Solution {
public:
    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        
        // Find all divisors of n
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        
        vector<int> best_result;
        int min_diff = INT_MAX;
        
        // Backtrack to find optimal split
        vector<int> current;
        backtrack(n, k, divisors, current, best_result, min_diff);
        
        return best_result;
    }
    
private:
    void backtrack(int remaining, int parts_left, const vector<int>& divisors, 
                   vector<int>& current, vector<int>& best_result, int& min_diff) {
        // Base case: only one part left
        if (parts_left == 1) {
            current.push_back(remaining);
            
            // Calculate difference for current split
            int max_val = *max_element(current.begin(), current.end());
            int min_val = *min_element(current.begin(), current.end());
            int diff = max_val - min_val;
            
            // Update best result if this is better
            if (diff < min_diff) {
                min_diff = diff;
                best_result = current;
            }
            
            current.pop_back();
            return;
        }
        
        // Try each valid divisor
        for (int d : divisors) {
            if (d > remaining) break;
            if (remaining % d != 0) continue;
            
            // Pruning: if current max difference already exceeds best, skip
            if (!current.empty()) {
                int current_max = max(*max_element(current.begin(), current.end()), d);
                int current_min = min(*min_element(current.begin(), current.end()), d);
                if (current_max - current_min >= min_diff) continue;
            }
            
            current.push_back(d);
            backtrack(remaining / d, parts_left - 1, divisors, current, best_result, min_diff);
            current.pop_back();
        }
    }
};