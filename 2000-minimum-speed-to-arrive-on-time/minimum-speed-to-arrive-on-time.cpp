class Solution {
public:
    double calculateTime(const vector<int>& dist, int speed) {
        double time = 0;
        int n = dist.size();

        // Handle all except the last element using integer division
        for (int i = 0; i < n-1 ; i++)
            time += (dist[i] + speed - 1) / speed;  // Equivalent to ceil(dist[i] / speed)

        // Handle the last element explicitly
        time += (double)dist[n - 1] / speed; // Last segment is exact

        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e7, ans = -1;

        while (left <= right) {
            int mid = (left + right) >> 1 ;

            if (calculateTime(dist, mid) <= hour) {
                ans = mid;  // Found a valid speed, try a lower one
                right = mid - 1;
            } else {
                left = mid + 1;  // Need more speed
            }
        }

        return ans;
    }
};
