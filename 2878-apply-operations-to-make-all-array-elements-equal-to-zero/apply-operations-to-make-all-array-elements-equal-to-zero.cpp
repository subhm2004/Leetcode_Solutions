class Solution {
public:
    // Helper function to apply all range operations using difference array
    vector<int> apply_difference_array(vector<vector<int>>& operations, int n) {
        vector<int> diff(n + 1, 0);  // +1 to safely handle r + 1

        // Step 1: Apply each range update
        for (const auto& op : operations) {
            int l = op[0];
            int r = op[1];
            int val = op[2];

            diff[l] += val;
            if (r + 1 <= n)
                diff[r + 1] -= val;
        }

        // Step 2: Convert difference array to actual values using prefix sum
        for (int i = 1; i <= n; ++i) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }

    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> operations;
        vector<int> applied(n, 0);  // stores the actual values after applying operations
        vector<int> current_diff(n + 1, 0); // temporary difference array to track total effect
        int total = 0;

        for (int i = 0; i < n; ++i) {
            total += current_diff[i];  // apply all past operations till index i
            int value = nums[i] - total;

            if (value < 0) return false;
            if (value == 0) continue;

            if (i + k > n) return false;

            // Store the operation (range update)
            operations.push_back({i, i + k - 1, value});

            // Also update current_diff to simulate the ongoing effect
            current_diff[i] += value;
            current_diff[i + k] -= value;
            total += value;
        }

        // After collecting all operations, apply them to get final array
        applied = apply_difference_array(operations, n);

        // Final array should match target = all zeros
        for (int i = 0; i < n; ++i) {
            if (nums[i] - applied[i] != 0)
                return false;
        }

        return true;
    }
};
