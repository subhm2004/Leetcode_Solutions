class Solution {
private:
    // orientation check
    // 0 → collinear, 1 → clockwise, 2 → counterclockwise
    int orientation(vector<int>& p, vector<int>& c, vector<int>& n) {
        long long val = 1LL * (c[1] - p[1]) * (n[0] - c[0]) - 
                        1LL * (c[0] - p[0]) * (n[1] - c[1]);
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }
    
    // distance square
    long long distSq(vector<int>& a, vector<int>& b) {
        return 1LL * (a[0] - b[0]) * (a[0] - b[0]) + 
               1LL * (a[1] - b[1]) * (a[1] - b[1]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n <= 1) return arr;
        // Special case: if all points are collinear
        bool allCollinear = true;
        if (n >= 3) {
            for (int i = 2; i < n; i++) {
                if (orientation(arr[0], arr[1], arr[i]) != 0) {
                    allCollinear = false;
                    break;
                }
            }
        }
        
        if (allCollinear) {
            sort(arr.begin(), arr.end());
            return arr;
        }
        
        // Step 1: Find lowest point
        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i][1] < arr[minIdx][1] || 
                (arr[i][1] == arr[minIdx][1] && arr[i][0] < arr[minIdx][0])) {
                minIdx = i;
            }
        }
        swap(arr[0], arr[minIdx]);
        
        // Step 2: Sort by polar angle wrt arr[0]
        sort(arr.begin() + 1, arr.end(), [&](vector<int>& c, vector<int>& n) {
            int o = orientation(arr[0], c, n);
            if (o == 0) // collinear
                return distSq(arr[0], c) < distSq(arr[0], n);
            return (o == 2); // keep counterclockwise first
        });
        
        // Step 3: Modified Graham Scan
        vector<vector<int>> hull;
        hull.push_back(arr[0]);
        hull.push_back(arr[1]);
        
        for (int i = 2; i < n; i++) {
            while (hull.size() > 1 && 
                   orientation(hull[hull.size()-2], hull[hull.size()-1], arr[i]) == 1) {
                hull.pop_back();
            }
            hull.push_back(arr[i]);
        }
        
        // Add collinear points on boundary
        set<pair<int,int>> hullSet;
        for (auto& p : hull) {
            hullSet.insert({p[0], p[1]});
        }
        
        int hullSize = hull.size();
        for (int i = 0; i < hullSize; i++) {
            vector<int> current = hull[i];
            vector<int> next = hull[(i + 1) % hullSize];
            
            for (auto& p : arr) {
                if (hullSet.find({p[0], p[1]}) == hullSet.end() && 
                    orientation(current, next, p) == 0) {
                    if ((p[0] >= min(current[0], next[0]) && p[0] <= max(current[0], next[0])) &&
                        (p[1] >= min(current[1], next[1]) && p[1] <= max(current[1], next[1]))) {
                        hull.push_back(p);
                    }
                }
            }
        }
        
        return hull;
    }
};