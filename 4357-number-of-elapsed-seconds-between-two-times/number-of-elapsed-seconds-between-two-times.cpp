class Solution {
public:
    int helper(string t) {
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        int s = stoi(t.substr(6, 2));

        return h * 3600 + m * 60 + s;
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        return helper(endTime) - helper(startTime);
    }
};