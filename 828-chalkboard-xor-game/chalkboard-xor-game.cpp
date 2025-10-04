class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int total_xor = 0;
        for (int x : nums) total_xor ^= x;

        // Case 1: Agar start me hi XOR 0 hai -> Alice jeet jaayegi
        if (total_xor == 0) return true;

        // Case 2: Agar array length even hai -> Alice jeetegi
        return nums.size() % 2 == 0;
    }
};
