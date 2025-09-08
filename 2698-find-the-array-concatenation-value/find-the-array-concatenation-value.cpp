class Solution {
public:
    int find_power(int num) {
        int power = 1;
        while (num > 0) {
            power *= 10;
            num /= 10;
        }
        return power;
    }

    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            int a = nums[i], b = nums[j];
            long long concat = 1LL * a * find_power(b) + b;
            ans += concat;
            i++;
            j--;
        }

        // agar ek element bacha ho
        if (i == j) ans += nums[i];

        return ans;
    }
};