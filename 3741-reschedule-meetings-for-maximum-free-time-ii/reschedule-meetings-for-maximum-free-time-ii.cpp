//https://www.youtube.com/watch?v=nRQwEyJBW-I
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free_arr; //store durations of free gaps

        //ith event
        //ith start - i-1th ka end = free gap duration
        free_arr.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            free_arr.push_back(startTime[i] - endTime[i-1]);
        }

        free_arr.push_back(eventTime - endTime[endTime.size()-1]);

        int n = free_arr.size();
        vector<int> max_right_free(n, 0);
        vector<int> max_left_free(n, 0);
        for(int i = n-2; i >= 0; i--) {
            max_right_free[i] = max(max_right_free[i+1], free_arr[i+1]);
        }

        for(int i = 1; i < n; i++) {
            max_left_free[i] = max(max_left_free[i-1], free_arr[i-1]);
        }


        int ans = 0;
        //Iterating on the free_arr
        for(int i = 1; i < n; i++) {
            int curr_event_time = endTime[i-1] - startTime[i-1]; //duration of event = d

            //Case-1 Moving completely out
            if(curr_event_time <= max(max_left_free[i-1], max_right_free[i])) {
                ans = max(ans, free_arr[i-1] + curr_event_time + free_arr[i]);
            }

            //case-2 shift left or right
            ans = max(ans, free_arr[i-1] + free_arr[i]);
        }

        return ans;


    }
};
