class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int min = *min_element(nums.begin(), nums.end());

        int moves = 0;
        for (int num : nums) {
            moves += num - min;
        }

        return moves;
    }
};