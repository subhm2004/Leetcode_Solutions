class Solution {
public:
    long long solve(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        long long total_pair = 0;
        unordered_map<long long, long long> mp;

        for (int i = 0; i < n; i++) {
            long long sq = 1LL * nums1[i] * nums1[i];
            mp[sq]++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                long long prod = 1LL * nums2[i] * nums2[j];
                total_pair += mp[prod];
            }
        }

        return total_pair;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {

        long long ans = 0;

        ans += solve(nums1, nums2);
        ans += solve(nums2, nums1);

        return (int)ans;
    }
};
