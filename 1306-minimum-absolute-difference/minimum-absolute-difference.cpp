class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;  
        int minDiff = INT_MAX; 

        // Sort kar rahe hain array ko taaki consecutive elements ke beech ka difference calculate kar sakein.
        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];  // consecutive elements ke beech ka difference

            if (diff < minDiff) {
                minDiff = diff;
                ans = {{arr[i - 1], arr[i]}};
            }
            // Agar current difference minDiff ke barabar hai, toh uss pair ko ans mein add kar rahe hain
            else if (diff == minDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;  
    }
};
