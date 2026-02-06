// // Sorting + Sliding Window ( minimium removal or deletion = total length - maximum balanced)
// class Solution { 
// public:
//     int minRemoval(vector<int>& nums, int k) {

//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         int left = 0;
//         int max_len = 1;

//         for (int right = 0; right < n; right++) {

//             while (nums[right] > 1LL * nums[left] * k) {
//                 left++;
//             }

//             max_len = max(max_len, right - left + 1);
//         }

//         return n - max_len;
//     }
// };

// Binary Seach + Sorting 
class Solution {
public:
    int minRemoval(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            long long limit = 1LL * a[i] * k;
            int l = i;
            int r = n - 1;
            int j = i;

            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[mid] <= limit) {
                    j = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            maxi = max(maxi, j - i + 1);
        }
        return n - maxi;
    }
};