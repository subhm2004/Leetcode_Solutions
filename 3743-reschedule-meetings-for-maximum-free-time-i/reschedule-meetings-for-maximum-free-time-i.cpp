class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free_arr; //store durations of free gaps

        //ith event
        //ith start - i-1th ka end = free gap duration
        free_arr.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            free_arr.push_back(startTime[i] - endTime[i-1]);
        }

        free_arr.push_back(eventTime - endTime[endTime.size()-1]);

        //Khandani sliding window

        int max_sum = INT_MIN;
        int curr_sum = 0;
        int i = 0;
        int n = free_arr.size();

        for (int j = 0; j < n; j++) {
            curr_sum += free_arr[j];

            // Window size control: agar window ka size k+1 se zyada ho gaya to shrink karo
            if (j - i + 1 > k + 1) {
                curr_sum -= free_arr[i];
                i++;
            }

            // Har step pe max_sum update karo
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;

    }
};
