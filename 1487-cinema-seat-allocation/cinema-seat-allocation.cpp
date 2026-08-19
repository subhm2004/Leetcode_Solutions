class Solution {
public:
    bool is_available(const vector<bool>& visited_seat, int start) { // start .. start+3
        return !visited_seat[start] && !visited_seat[start + 1] &&
               !visited_seat[start + 2] && !visited_seat[start + 3];
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp; // row_no -> booked seats

        for (auto& rs : reservedSeats) {
            mp[rs[0]].push_back(rs[1]);
        }

        int ans = (n - (int)mp.size()) * 2; // untouched rows -> 2 groups each

        for (auto& [row, booked_seats] : mp) {
            vector<bool> visited_seat(11, false); // seats 1..10

            for (int s : booked_seats) {
                visited_seat[s] = true;
            }

            bool group_A = is_available(visited_seat, 2); // 2,3,4,5
            bool group_B = is_available(visited_seat, 4); // 4,5,6,7
            bool group_C = is_available(visited_seat, 6); // 6,7,8,9

            if (group_A && group_C) {
                ans += 2;
            } else if (group_A || group_B || group_C) {
                ans += 1;
            } else {
                ans += 0;
            }
        }

        return ans;
    }
};