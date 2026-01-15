class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_Length = 0; // Maximum length ka track rakhne ke liye
        int left = 0;       // Window ka left pointer
        int zero_Count = 0;  // Kitne 0s aaye hai, yeh count karega

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0)
                zero_Count++; // Agar 0 mila to count badhao

            // Jab zero_Count k se zyada ho jaye, to window ko adjust karo
            while (zero_Count > k) {
                if (nums[left] == 0)
                    zero_Count--; // Left side se ek 0 hatao
                left++;          // Window ka size chhota karo
            }

            // Maximum valid window size update karo
            max_Length = max(max_Length, right - left + 1);
        }

        return max_Length;
    }
};
