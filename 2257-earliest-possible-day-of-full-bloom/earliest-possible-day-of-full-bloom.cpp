// Jo seed grow hone me zyada time leta hai, use pehle plant karo
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();

        
        priority_queue<pair<int,int>> pq; // max heap based on growTime

        for (int i = 0; i < n; i++) {
            pq.push({growTime[i], plantTime[i]});
        }

        int curr_plant_time = 0;
        int ans = 0;

        while (!pq.empty()) {
            auto [g, p] = pq.top();
            pq.pop();

            curr_plant_time += p;
            ans = max(ans, curr_plant_time + g);
        }

        return ans;
    }
};