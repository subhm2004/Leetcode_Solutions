class Solution {
public:
     bool is_Possible(const vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor; // ceiling division
            // sum += ceil((double)num / divisor);

        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (is_Possible(nums, mid, threshold)) {
                ans = mid;         
                right = mid - 1;
            } else {
                left = mid + 1;     
            }
        }

        return ans;
    }
};