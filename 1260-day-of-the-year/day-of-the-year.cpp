class Solution {
public:
    bool is_leap(int year) {
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        return (year % 4 == 0);
    }

    int month_days(int month, int year) {
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12)
            return 31;

        if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30;

        // February
        return is_leap(year) ? 29 : 28;
    }

    int dayOfYear(string date) {
        int year  = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day   = stoi(date.substr(8, 2));

        int ans = day;

        for (int m = 1; m < month; m++) {
            ans += month_days(m, year);
        }

        return ans;
    }
};
