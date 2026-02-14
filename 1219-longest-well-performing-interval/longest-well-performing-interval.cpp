class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int max_len = 0;
        
        for (int i = 0; i < n; i++) {
            int tiring_days = 0;
            int non_tiring_days = 0;
            
            for (int j = i; j < n; j++) {
                // Current day count karo
                if (hours[j] > 8) {
                    tiring_days++;
                } else {
                    non_tiring_days++;
                }
                
                // Agar tiring days zyada hai
                if (tiring_days > non_tiring_days) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        
        return max_len;
    }
};