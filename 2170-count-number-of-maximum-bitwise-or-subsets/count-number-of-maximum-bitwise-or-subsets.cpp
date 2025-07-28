class Solution {
public:
    int max_OR = 0, count = 0;

    void solveRE(vector<int>& nums, int i, int curr_OR) {
        if (i == nums.size()) {
            if (curr_OR == max_OR)
                count++; // agar current subset ka OR == max_OR hai to count badhao
            return;
        }

        // INCLUDE current element
        solveRE(nums, i + 1, curr_OR | nums[i]);

        // EXCLUDE current element
        solveRE(nums, i + 1, curr_OR);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // Step 1: Pehle max_OR find karo by doing OR of all elements
        for (int x : nums)
            max_OR |= x;

        // Step 2: Recursively find all subsets using include-exclude
        solveRE(nums, 0, 0);

        return count;
    }
};
