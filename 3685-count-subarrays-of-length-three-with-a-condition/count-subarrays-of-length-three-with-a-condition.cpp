class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {                  // First element
            for (int j = i + 2; j < n; ++j) {           // Third element (minimum gap of 2)
                if (j - i == 2) {                       // Only subarrays of length 3
                    int a = nums[i];
                    int b = nums[i + 1];
                    int c = nums[j];

                    if (b % 2 == 0 && (a + c) == (b / 2)) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};

