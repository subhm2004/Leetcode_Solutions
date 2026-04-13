class Solution {
public:
    long long mod = 1e9 + 7;

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        
        vector<pair<int,int>> arr;

        int n = nums1.size();

        for(int i = 0; i < n; i++) {
            arr.push_back({nums1[i], nums0[i]});
        }

        sort(arr.begin(), arr.end(), [&](auto &a, auto &b) {
            
            string x = string(a.first, '1') + string(a.second, '0');
            string y = string(b.first, '1') + string(b.second, '0');

            return x + y > y + x;
        });

        long long ans = 0;

        for(auto [ones, zeros] : arr) {

            for(int i = 0; i < ones; i++) {
                ans = (ans * 2 + 1) % mod;
            }

            for(int i = 0; i < zeros; i++) {
                ans = (ans * 2) % mod;
            }
        }

        return ans;
    }
};