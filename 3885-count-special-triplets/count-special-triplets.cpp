// class Solution { // TLE 947/1121
// public:
//     int specialTriplets(vector<int>& nums) {
//         int n = nums.size();
//         long long count = 0;
//         int MOD = 1e9 + 7;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 for (int k = j + 1; k < n; ++k) {
//                     if (nums[i] == 2 * nums[j] && nums[k] == 2 * nums[j]) {
//                         count = (count + 1) % MOD;
//                     }
//                 }
//             }
//         }

//         return count;
//     }
// };

// class Solution {        // TLE 1098/1121
// public:
//     int specialTriplets(vector<int>& nums) {
//         int n = nums.size();
//         long long ans = 0;
//         const int MOD = 1e9 + 7;

//         for (int j = 0; j < n; ++j) {
//             long long count_Left = 0;
//             long long count_Right = 0;

//             for (int i = 0; i < j; ++i) {
//                 if (nums[i] == 2 * nums[j]) count_Left++;
//             }

//             for (int k = j + 1; k < n; ++k) {
//                 if (nums[k] == 2 * nums[j]) count_Right++;
//             }

//             ans = (ans + (count_Left * count_Right) % MOD) % MOD;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;

        unordered_map<long long, int> left,
            right; // left: j ke pehle wale numbers ka count, right: j ke baad
                   // wale numbers ka count

        // Sabhi numbers ka count right map mein store kar liya (abhi tak hum
        // kisi element pe nahi aaye)
        for (int num : nums)
            right[num]++;

        long long ans = 0; // Final answer store karne ke liye

        // Har index ko j maan ke loop chalayenge (j beech wala hoga triplet
        // mein)
        for (int j = 0; j < nums.size(); ++j) {
            right[nums[j]]--; // Ab hum j pe aa gaye hain, to right se is number
                              // ka ek count kam kar diya

            long long x = nums[j] * 2LL; // Hume aise i aur k chahiye jinke
                                         // value 2 * nums[j] ke barabar ho

            int count_left =
                left[x]; // Check karo left mein x kitni baar aaya hai (valid i)
            int count_right =
                right[x]; // Check karo right mein x kitni baar aayega (valid k)

            // Total valid triplets = count_left * count_right
            ans = (ans + 1LL * count_left * count_right) % MOD;

            left[nums[j]]++; // j ko left mein daal diya (kyunki ab j ke aage
                             // badh chuke hain)
        }

        return ans;
    }
};
