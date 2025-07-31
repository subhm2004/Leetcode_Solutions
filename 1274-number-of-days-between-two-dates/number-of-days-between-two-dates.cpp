class Solution {
public:
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int countDays(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));

        vector<int> daysInMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int days = 0;

        for (int year = 1971; year < y; ++year) {
            days += isLeap(year) ? 366 : 365;
        }

        for (int i = 0; i < m - 1; ++i) {
            days += daysInMonth[i];
        }

        if (m > 2 && isLeap(y)) {
            days += 1;
        }

        days += d;
        return days;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(countDays(date1) - countDays(date2));
    }
};
