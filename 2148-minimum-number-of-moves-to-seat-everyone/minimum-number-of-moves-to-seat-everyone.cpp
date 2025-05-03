class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.rbegin(), seats.rend());
        sort(students.rbegin(), students.rend());
        
        int totalMoves = 0;
        for (int i = 0; i < seats.size(); ++i) {
            totalMoves += abs(seats[i] - students[i]);
        }
        return totalMoves;
    }
};
