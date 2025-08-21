class Solution {
public:
        int rectangles_in_histogram(vector<int>& heights) {
        int n = heights.size();
        int count = 0;
        
         for (int i = 0; i < n; i++) {
            int minHeight = heights[i];
            
             for (int j = i; j >= 0 && heights[j] > 0; j--) {
                minHeight = min(minHeight, heights[j]);
                 count += minHeight;
            }
        }
        
        return count;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int totalCount = 0;
        
         vector<int> heights(n, 0);
        
        for (int i = 0; i < m; i++) {
             for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            
             totalCount += rectangles_in_histogram(heights);
        }
        
        return totalCount;
    }
};