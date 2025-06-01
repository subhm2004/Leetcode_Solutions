class Solution {
public:
    bool found = false;

    void backtrack(vector<int>& nums, int index, vector<int>& subset_A, vector<bool>& visited, long long prod_A, long long target) {
        if (prod_A > target || found) return;  // Prune if product exceeds or solution already found

        int n = nums.size();

        // If subset_A is not empty and not the whole array
        if (!subset_A.empty() && subset_A.size() < n) {
            long long prod_B = 1;
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    prod_B *= nums[i];
                    if (prod_B > target) break;
                }
            }

            if (prod_A == target && prod_B == target) {
                found = true;
                return;
            }
        }

        for (int i = index; i < n; ++i) {
            if (found) return;
            subset_A.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, i + 1, subset_A, visited, prod_A * nums[i], target);
                        subset_A.pop_back();

            visited[i] = false;
            // subset_A.pop_back();
        }
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> subset_A;
        found = false;
        backtrack(nums, 0, subset_A, visited, 1, target);
        return found;
    }
};
