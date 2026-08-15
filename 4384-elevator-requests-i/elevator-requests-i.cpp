class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int current_floor = 0;
        int total_time = 0;

        for (int floor : requests) {

            // Current floor se requested floor tak ka distance
            total_time += abs(current_floor - floor);

            // Elevator ab isi floor par hai
            current_floor = floor;
        }

        return total_time;
    }
};