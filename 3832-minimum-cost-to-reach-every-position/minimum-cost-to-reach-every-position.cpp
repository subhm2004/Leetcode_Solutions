class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        
        for (int i = 1; i < n; i++) {
            cost[i] = min(cost[i], cost[i - 1]); 
        }
        
        return cost;
    }
};
