class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;

        // Yeh map store karega: remainder -> uska pehla index
        unordered_map<int, int> remainder_idx;

        // Jab remainder 0 ho, toh iska matlab subarray start se hi valid ho sakta hai
        remainder_idx[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // Agar k 0 nahi hai toh modulo le lo
            if (k != 0)
                sum %= k;

            // Agar yeh remainder pehle se map mein hai
            if (remainder_idx.count(sum)) {
                int prev_idx = remainder_idx[sum];

                // Check karo ki length kam se kam 2 ho
                if (i - prev_idx > 1)
                    return true;
            } else {
                // Agar yeh remainder pehli baar aaya hai, toh store karo
                remainder_idx[sum] = i;
            }
        }

        // Koi valid subarray nahi mila
        return false;
    }
};
