class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();

        // Helper function to check if can make all elements == target within k operations
        auto helper = [&](int target) -> bool {
            vector<int> arr = nums;
            int operations = 0;

            for (int i = 0; i < n - 1; i++) {
                if (arr[i] != target) {
                    // flip arr[i] and arr[i+1]
                    arr[i] = -arr[i];
                    arr[i + 1] = -arr[i + 1];
                    operations++;
                    if (operations > k) return false;
                }
            }

            // After processing all but last element, check if last element matches target
            return arr[n - 1] == target;
        };

        // Check for target 1 and target -1
        return helper(1) || helper(-1);
    }
};
