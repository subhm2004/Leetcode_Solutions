class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int maxByWeight = maxWeight / w;  // Maximum containers possible by weight limit
        int maxByGrid = n * n;            // Maximum containers that fit in the grid
        
        return min(maxByWeight, maxByGrid);  // The answer is the minimum of both limits
    }
};
