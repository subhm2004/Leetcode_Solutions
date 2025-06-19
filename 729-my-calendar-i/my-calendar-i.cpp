class MyCalendar {
    vector<pair<int, int>> bookings;

public:
    MyCalendar() {
        // Initially, no bookings
    }

    bool book(int start, int end) {
        for (auto [s, e] : bookings) {
            // If overlap found
            if (start < e && s < end) {
                return false;
            }
        }
        // If no overlap, add the booking
        bookings.emplace_back(start, end);
        return true;
    }
};
