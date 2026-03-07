class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int num = abs(arr[i]);

            int idx = num - 1;

            if (arr[idx] < 0) {
                ans.push_back(num);
            } else {
                arr[idx] *= -1;
            }
        }
        return ans;
    }
};