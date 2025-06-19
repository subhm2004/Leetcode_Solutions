class Solution {
public:
    int to_Minutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start_1 = to_Minutes(event1[0]);
        int end_1   = to_Minutes(event1[1]);
        int start_2 = to_Minutes(event2[0]);
        int end_2   = to_Minutes(event2[1]);

        // agar (end_1 < start_2 || end_2 < start_1) to conflict exist nhi krta 

        // Conflict exists krega agar interval overlap krenge
        return !(end_1 < start_2 || end_2 < start_1);
    }
};
