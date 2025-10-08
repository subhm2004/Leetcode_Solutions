class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n);
        unordered_map<int, int> last_full_day; // lake -> last day it got full
        set<int> sunny_days;                  // indices of sunny days

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                int lake = rains[i];
                if (last_full_day.count(lake)) {
                    // lake is full, need to find a sunny day to dry it
                    bool dried = false;
                    for (int sd : sunny_days) {
                        if (sd > last_full_day[lake]) {
                            ans[sd] = lake; // dry this lake
                            sunny_days.erase(sd);
                            dried = true;
                            break;
                        }
                    }
                    if (!dried)
                        return {}; // no sunny day to dry → flood
                }
                last_full_day[lake] = i;
                ans[i] = -1;
            } else {
                sunny_days.insert(i); // mark this day as sunny
            }
        }

        // For remaining sunny days, dry any lake chzlo ki day 1 ko dry kr dete hai
        for (int sd : sunny_days)
            ans[sd] = 1;

        return ans;
    }
};