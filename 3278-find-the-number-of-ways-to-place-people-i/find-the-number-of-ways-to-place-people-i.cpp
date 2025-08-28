struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 1) ^ p.second);
    }
};

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<pair<int,int>, pair_hash> st;
        
        // store all points in a set for O(1) 
        for (auto &p : points) {
            st.insert({p[0], p[1]});
        }
        
        int ans = 0;
        
        // check every pair (A,B)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                int Ax = points[i][0], Ay = points[i][1];
                int Bx = points[j][0], By = points[j][1];
                
                // condition: A is upper-left of B (including same coordinates)
                if (Ax <= Bx && Ay >= By) {
                    bool valid = true;
                    
                    // check if any other point lies inside rectangle (or on border)
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int Cx = points[k][0], Cy = points[k][1];
                        if (Ax <= Cx && Cx <= Bx && By <= Cy && Cy <= Ay) {
                            valid = false;
                            break;
                        }
                    }
                    
                    if (valid) ans++;
                }
            }
        }
        return ans;
    }
};