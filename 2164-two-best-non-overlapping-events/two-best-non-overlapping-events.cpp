class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<tuple<int, int, bool>> custom_event; // { time, value, isStart }
        int maxi = 0;
        int ans = 0;
        for (auto& event : events) {
            custom_event.push_back(
                make_tuple(event[0], event[2], true)); // Start of an event
            custom_event.push_back(
                make_tuple(event[1] + 1, event[2], false)); // End of an event
        }
        sort(custom_event.begin(), custom_event.end(), [](auto& a, auto& b) {
            return get<0>(a) == get<0>(b) ? get<2>(a) < get<2>(b)
                                          : get<0>(a) < get<0>(b);
        });
        for (auto& [time, value, isStart] : custom_event) {
            if (isStart) {
                ans = max(ans, value + maxi);
            } else {
                maxi = max(maxi, value);
            }
        }
        return ans;
    }
};
