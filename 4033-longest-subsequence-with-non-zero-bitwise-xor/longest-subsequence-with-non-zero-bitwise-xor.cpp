class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        for (int x : nums) {
            total_xor ^= x; // sab elements ka XOR nikal rahe hain
        }

        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0; // agar sab 0 hain, koi non-zero XOR subsequence nahi
        }

        if (total_xor == 0) {
            return nums.size() - 1; // agar XOR 0 hai, to ek element hata do
        }
        
        return nums.size(); // XOR already non-zero hai, poora array le lo
    }
};
