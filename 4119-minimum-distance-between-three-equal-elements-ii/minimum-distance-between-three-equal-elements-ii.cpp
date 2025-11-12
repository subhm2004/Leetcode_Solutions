// Modified Equation
// |i-j| + |j-k| + |k-i| = (j - i) + (k- j) + (k - i) = 2 * (k - i)
// 2 × (max_index - min_index)


class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        // Step 1: Store all positions of each number
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Step 2: For each number, check if it occurs ≥ 3 times
        for (auto& [num, indices] : pos) {
            int m = indices.size();
            if (m < 3) continue;

            // Step 3: Check consecutive triplets
            for (int i = 0; i + 2 < m; i++) {
                int dist = 2 * (indices[i + 2] - indices[i]);
                ans = min(ans, dist);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};