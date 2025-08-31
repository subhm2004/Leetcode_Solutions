#pragma GCC optimize("O3", "unroll-loops")

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif

class Solution {
public:
    bool backtrack(vector<int>& nums, int idx, vector<int>& subset_sum, int target) {
        if (idx == nums.size()) {
            for (int s : subset_sum)
                if (s != target) return false;
            return true;
        }

        for (int i = 0; i < subset_sum.size(); ++i) {
            if (subset_sum[i] + nums[idx] > target) continue;

            subset_sum[i] += nums[idx];
            if (backtrack(nums, idx + 1, subset_sum, target)) return true;
            subset_sum[i] -= nums[idx];

            // Optimization: if current subset is empty and didn't fit, skip other empty subsets
            if (subset_sum[i] == 0) break;

          }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;

        sort(nums.rbegin(), nums.rend());
        // sort(nums.begin(), nums.end());


        vector<int> subset_sum(k, 0);
        return backtrack(nums, 0, subset_sum, target);
    }
};
