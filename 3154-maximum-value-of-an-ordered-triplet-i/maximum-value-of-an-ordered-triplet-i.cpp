// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long long maxTriplet = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     long long value = (nums[i] - nums[j]) * 1LL * nums[k];
//                     maxTriplet = max(maxTriplet, value);
//                 }
//             }
//         }
//         return maxTriplet;
//     }
// };
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++) {
            ans = max(ans, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, 1LL * nums[k]);
        }
        return ans;
    }
};