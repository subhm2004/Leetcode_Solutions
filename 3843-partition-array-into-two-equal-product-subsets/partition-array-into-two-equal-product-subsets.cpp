class Solution {
public:
    bool found = false;

    void backtrack(vector<int>& nums, int index, vector<int>& subsetA, vector<bool>& visited, long long prodA, long long target) {
        if (prodA > target || found) return;  // Prune if product exceeds or solution already found

        int n = nums.size();

        // If subsetA is not empty and not the whole array
        if (!subsetA.empty() && subsetA.size() < n) {
            long long prodB = 1;
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    prodB *= nums[i];
                    if (prodB > target) break;
                }
            }
            if (prodA == target && prodB == target) {
                found = true;
                return;
            }
        }

        for (int i = index; i < n; ++i) {
            if (found) return;
            subsetA.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, i + 1, subsetA, visited, prodA * nums[i], target);
            visited[i] = false;
            subsetA.pop_back();
        }
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> subsetA;
        found = false;
        backtrack(nums, 0, subsetA, visited, 1, target);
        return found;
    }
};
