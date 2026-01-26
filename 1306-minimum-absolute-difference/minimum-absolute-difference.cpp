class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int min_diff = INT_MAX;
        sort(arr.begin(), arr.end());
        
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];

            if (diff < min_diff) {
                min_diff = diff;
                ans = {{arr[i - 1], arr[i]}};
            }
            
            else if (diff == min_diff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return ans;
    }
};