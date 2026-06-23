class Solution {
public:
    int first_digit(long long num) {

        while (num >= 10) {
            num /= 10;
        }

        return num;
    }

    int last_digit(long long num) { return num % 10; }

    long long countValidSubarrays(vector<int>& nums, int x) {

        int n = nums.size();

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long sum = 0;

            for (int j = i; j < n; j++) {

                sum += nums[j];

                if (last_digit(sum) == x && first_digit(sum) == x) {
                    ans++;
                }
            }
        }

        return ans;
    }
};