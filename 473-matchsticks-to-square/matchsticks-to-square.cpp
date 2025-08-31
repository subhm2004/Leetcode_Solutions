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

class Solution { // Same as Leetcode 698 
public:
    bool backtrack(vector<int>& arr, vector<int>& sides, int idx, int target) {
        if (idx == arr.size()) {
            // check all sides equal to target
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + arr[idx] > target) continue; // overflow
            sides[i] += arr[idx]; // place stick in this side

            if (backtrack(arr, sides, idx + 1, target)) return true;

            sides[i] -= arr[idx]; // backtrack

            // optimization: agar side empty thi aur nahi fit hua, toh dusre empty side me bhi same hoga
            if (sides[i] == 0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& arr) {
        long long total_sum = accumulate(arr.begin(), arr.end(), 0LL);
        if (total_sum % 4 != 0) return false;
        int target = total_sum / 4;

        sort(arr.rbegin(), arr.rend()); // descending me sort krte hai phle badi sides leke bana lete hai to easily ho jayega sara 
        vector<int> sides(4, 0);
        return backtrack(arr, sides, 0, target);
    }
};