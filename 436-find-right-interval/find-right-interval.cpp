class Solution { // Binary Search 
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> arr;  // {start, original_idx}
        
        for(int i = 0; i < n; i++) {
            arr.push_back({intervals[i][0], i});
        }
        
        // Sort by start
        sort(arr.begin(), arr.end());
        
        vector<int> ans(n, -1);
        
        for(int i = 0; i < n; i++) {
            int end_val = intervals[i][1];
            
            // Binary search in arr array
            int l = 0, r = n - 1, idx = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(arr[mid].first >= end_val) {
                    idx = arr[mid].second; // candidate mila
                    r = mid - 1;              // aur chhota dhundo
                } else {
                    l = mid + 1;
                }
            }
            
            ans[i] = idx;
        }
        
        return ans;
    }
};

