class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        for (int spell : spells) {
            long long min_potion = ceil(1.0 * success / spell);
            int left = 0;
            int right = m - 1;
            int idx = m;

            while (left <= right) {
                int mid = (left + right) >> 1;

                if (min_potion <= potions[mid]) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans.push_back(m - idx);
        }
        return ans;
    }
};

// class Solution { // Brute Force
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
//     long long success) {
//         int n = spells.size();
//         int m = potions.size();
//         vector<int> ans(n, 0);
//         for(int i = 0; i < n; i++){
//             int count = 0;
//             for(int j = 0; j < m; j++){
//                 if((long long)spells[i] * potions[j] >= success)
//                     count++;
//             }
//             ans[i] = count;
//         }
//         return ans;
//     }
// };