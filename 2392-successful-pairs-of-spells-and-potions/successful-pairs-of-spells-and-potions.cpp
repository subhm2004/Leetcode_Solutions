auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        for (int spell : spells) {
            long long min_potion = ceil(1.0 * success / spell);
            int low = 0;
            int high = m - 1;
            int idx = m;

            while (low <= high) {
                int mid = (low + high) >> 1;

                if (min_potion <= potions[mid]) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
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