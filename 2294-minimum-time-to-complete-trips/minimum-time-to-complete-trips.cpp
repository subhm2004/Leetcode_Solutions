class Solution {
public:
    // calculate number of trips possible in 'm' time
    long countTrips(vector<int>& time, long m) {
        long trip = 0;
        for (int t : time)
            trip += m / t; // Each bus can complete 'm / t' trips
        return trip;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long left = 1;
        long right = (long)(*min_element(time.begin(), time.end())) * totalTrips; 

        while (left < right) {
            long mid = (left + right) >> 1;
            if (countTrips(time, mid) >= totalTrips)
                right = mid;
            else
                left = mid + 1;
        }
        return left; 
    }
};
