class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll total_sum = 0;
        int count = 0;
        int smallest_loss = INT_MAX;

        for (ll num : nums) {
            int xored_val = num ^ k;

            // Agar XOR karne se value badh rahi hai toh use kar lo
            if (xored_val > num) {
                count++;
                total_sum += xored_val;
            } else {
                total_sum += num;
            }

            // Nuksaan track karo jab XOR beneficial na ho
            smallest_loss = min((ll)smallest_loss, abs(num - xored_val));
        }

        // Agar XORs ka count even hai toh sab sahi
        if (count % 2 == 0)
            return total_sum;

        // Warna, ek minimum nukasan waale ko hata do
        return total_sum - smallest_loss;
    }
};
