class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
    vector<int> ans(n);
    unordered_map<int,int> lastFullDay; // lake -> last day it got full
    set<int> sunnyDays; // indices of sunny days

    for (int i = 0; i < n; i++) {
        if (rains[i] > 0) {
            int lake = rains[i];
            if (lastFullDay.count(lake)) {
                // lake is full, need to find a sunny day to dry it
                bool dried = false;
                for (int sd : sunnyDays) {
                    if (sd > lastFullDay[lake]) {
                        ans[sd] = lake; // dry this lake
                        sunnyDays.erase(sd);
                        dried = true;
                        break;
                    }
                }
                if (!dried) return {}; // no sunny day to dry → flood
            }
            lastFullDay[lake] = i;
            ans[i] = -1;
        } else {
            sunnyDays.insert(i); // mark this day as sunny
        }
    }

    // For remaining sunny days, dry any lake (let's pick 1)
    for (int sd : sunnyDays) ans[sd] = 1;

    return ans;
    }
};