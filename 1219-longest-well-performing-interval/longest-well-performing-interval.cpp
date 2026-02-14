class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int max_len = 0;
        int prefix_sum = 0;
        unordered_map<int, int> first_occurence;
        
        for (int i = 0; i < hours.size(); i++) {
            // +1 for tiring day (>8), -1 for non-tiring day
            prefix_sum += (hours[i] > 8) ? 1 : -1;
            
            // Agar prefix sum positive hai, toh start se i tak well-performing hai
            if (prefix_sum > 0) {
                max_len = i + 1;
            }
            else {
                // Agar prefix_sum - 1 pehle dekha hai, toh valid interval mil gaya
                if (first_occurence.find(prefix_sum - 1) != first_occurence.end()) {
                    max_len = max(max_len, i - first_occurence[prefix_sum - 1]);
                }
            }
            
            // First occurrence store karo
            if (first_occurence.find(prefix_sum) == first_occurence.end()) {
                first_occurence[prefix_sum] = i;
            }
        }
        
        return max_len;
    }
};