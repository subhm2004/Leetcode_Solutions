class Solution {
public:
    // Function to compute minimum circular distances for each index
    void computeMinDistances(vector<int>& nums, unordered_map<int, vector<int>>& indices, int size) {
        for (auto& [_, arr] : indices) {
            int m = arr.size();
            if (m == 1) {
                nums[arr[0]] = -1; // No duplicates
                continue;
            }
            for (int i = 0; i < m; i++) {
                int next = arr[(i + 1) % m];  // Next occurrence
                int prev = arr[(i - 1 + m) % m];  // Previous occurrence

                int forward = min(size - arr[i] + next, abs(arr[i] - next));
                int backward = min(abs(prev - arr[i]), arr[i] + size - prev);

                nums[arr[i]] = min(forward, backward);
            }
        }
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size(), size = nums.size();
        unordered_map<int, vector<int>> indices;

        // Store indices of each number
        for (int i = 0; i < size; i++) {
            indices[nums[i]].push_back(i);
        }

        // Compute minimum distances
        computeMinDistances(nums, indices, size);

        // Retrieve results for queries
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(nums[q]);
        }
        return ans;
    }
};
