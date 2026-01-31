class Solution {
public:
    vector<int> nums;

    bool is_possible(int k) {

        int operations = 0;

        for (int x : nums) {
            operations += (x + k - 1) / k;   // ceil(x / k)

            if (operations > 1LL * k * k)
                return false;
        }

        return operations <= 1LL * k * k;
    }

    int minimumK(vector<int>& nums) {
        this->nums = nums;

        int low = 1;
        int high = 1e5;
        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (is_possible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};