class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola_idx = -1;  // right se pehla aisa index jahan order break ho (nums[i] < nums[i+1])

        // Step 1: Right se check karo pehla index jahan nums[i] > nums[i-1] ho
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                gola_idx = i - 1;
                break;
            }
        }

        // Step 2: Agar aisa index mila, to usse bada rightmost element dhundo aur swap karo
        if (gola_idx != -1) {
            for (int j = n - 1; j > gola_idx; j--) {
                if (nums[j] > nums[gola_idx]) {
                    swap(nums[j], nums[gola_idx]);
                    break;
                }
            }
        }

        // Step 3: gola_idx ke baad waala pura part reverse kar do
        reverse(nums.begin() + gola_idx + 1, nums.end());
    }
};


// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(),nums.end());
//     }
// };