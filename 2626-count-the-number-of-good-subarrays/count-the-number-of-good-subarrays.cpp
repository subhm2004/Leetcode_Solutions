// class Solution {               Brute Force TLE 32/41
// public:
//     long long countGood(vector<int>& nums, int k) {
//         long long ans = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; ++i) {
//             unordered_map<int, int> freq;
//             long long pairCount = 0;

//             for (int j = i; j < n; ++j) {
//                 // Before increasing freq, count new pairs added
//                 pairCount += freq[nums[j]];
//                 freq[nums[j]]++;

//                 if (pairCount >= k) {
//                     ans++;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long ans = 0;
        long long pairs = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; ++right) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (pairs >= k) {
                ans += (n - right);
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return ans;
    }
};
