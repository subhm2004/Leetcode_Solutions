class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        // Sort by absolute value in descending order
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return llabs((long long)a) > llabs((long long)b);
        });

        // Take the two largest absolute values
        long long a = llabs((long long)nums[0]);
        long long b = llabs((long long)nums[1]);

        return 1e5 * a * b;
    }
};