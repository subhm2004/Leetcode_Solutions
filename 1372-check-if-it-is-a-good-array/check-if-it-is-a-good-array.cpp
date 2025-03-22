class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    bool isGoodArray(vector<int>& nums) {
        int ans = nums[0]; // Start with the first element
        for (int num : nums) {
            ans = gcd(ans, num);
            if (ans == 1)
                return true; // If GCD becomes 1, no need to check further
        }
        return ans == 1;
    }
};
