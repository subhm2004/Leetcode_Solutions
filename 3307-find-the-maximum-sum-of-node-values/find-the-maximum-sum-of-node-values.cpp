class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll totalSum = 0;
        int beneficialCount = 0;
        int smallestLoss = INT_MAX;

        for (ll num : nums) {
            int xoredValue = num ^ k;

            // Agar XOR karne se value badh rahi hai toh use kar lo
            if (xoredValue > num) {
                beneficialCount++;
                totalSum += xoredValue;
            } else {
                totalSum += num;
            }

            // Nuksaan track karo jab XOR beneficial na ho
            smallestLoss = min((ll)smallestLoss, abs(num - xoredValue));
        }

        // Agar beneficial XORs ka count even hai toh sab sahi
        if (beneficialCount % 2 == 0)
            return totalSum;

        // Warna, ek minimum nukasan waale ko hata do
        return totalSum - smallestLoss;
    }
};
