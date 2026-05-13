class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n/2; i++) {

            int a = nums[i];
            int b = nums[n-1-i];

            int minVal = min(a, b) + 1;
            int maxVal = max(a, b) + limit;

            diff[2] += 2;
            diff[2*limit+1] -= 2;

            //for moves = 1
            diff[minVal]   += (-1);
            diff[maxVal+1] -= (-1);

            //for moves = 0 [a+b, a+b]
            diff[a+b]   += (-1);
            diff[a+b+1] -= (-1);
        }

        int result = INT_MAX;

        for(int sum = 2; sum <= 2*limit; sum++) {
            diff[sum] += diff[sum-1];

            result = min(result, diff[sum]);
        }

        return result;
    }
};
