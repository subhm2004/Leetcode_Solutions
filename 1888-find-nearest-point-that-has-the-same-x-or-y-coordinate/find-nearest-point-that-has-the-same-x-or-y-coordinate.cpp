class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<int> distances(points.size(), INT_MAX);
        
        for (int i = 0; i < points.size(); ++i) {
            int ai = points[i][0];
            int bi = points[i][1];
            
            // Check if the point is valid
            if (ai == x || bi == y) {
                // Calculate Manhattan distance
                distances[i] = abs(x - ai) + abs(y - bi);
            }
        }
        
        // Find the minimum distance
        int min_distance = *min_element(distances.begin(), distances.end());
        
        // If no valid points, return -1
        if (min_distance == INT_MAX) {
            return -1;
        }
        
        // Find the smallest index with min_distance
        for (int i = 0; i < distances.size(); ++i) {
            if (distances[i] == min_distance) {
                return i;
            }
        }
        
        return -1;  
    }
};