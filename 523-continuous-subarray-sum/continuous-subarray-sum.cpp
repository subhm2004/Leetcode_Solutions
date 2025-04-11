// class Solution {                   TLE 94/101
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             int sum = 0;
//             for (int j = i; j < n; ++j) {
//                 sum += nums[j];
//                 if (j - i + 1 >= 2) {
//                     if (k == 0) {
//                         if (sum == 0)
//                             return true;
//                     } else {
//                         if (sum % k == 0)
//                             return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;

        // Yeh map store karega: remainder -> uska pehla index
        unordered_map<int, int> remainder_Index;

        // Jab remainder 0 ho, toh iska matlab subarray start se hi valid ho sakta hai
        remainder_Index[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // Agar k 0 nahi hai toh modulo le lo
            if (k != 0)
                sum %= k;

            // Agar yeh remainder pehle se map mein hai
            if (remainder_Index.count(sum)) {
                int prevIndex = remainder_Index[sum];

                // Check karo ki length kam se kam 2 ho
                if (i - prevIndex > 1)
                    return true;
            } else {
                // Agar yeh remainder pehli baar aaya hai, toh store karo
                remainder_Index[sum] = i;
            }
        }

        // Koi valid subarray nahi mila
        return false;
    }
};
