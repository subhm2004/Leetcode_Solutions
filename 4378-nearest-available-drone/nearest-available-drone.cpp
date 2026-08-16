class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {

        int ans = -1;
        int min_distance = INT_MAX;

        for (int i = 0; i < drones.size(); i++) {

            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            int distance = abs(x - target[0]) + abs(y - target[1]);

             if (distance <= range) {

                 if (distance < min_distance) {
                    min_distance = distance;
                    ans = i;
                }
            }
        }

        return ans;
    }
};