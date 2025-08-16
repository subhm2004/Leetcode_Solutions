class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size();

        int max_time = events[0][1];    
        int ans = events[0][0];         

        for (int i = 1; i < n; i++) {
            int time_taken = events[i][1] - events[i-1][1];  

             if (time_taken > max_time || 
               (time_taken == max_time && events[i][0] < ans)) {
                max_time = time_taken;
                ans = events[i][0];
            }
        }
        return ans;
    }
};