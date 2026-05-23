class Solution {
public:
    
    int minimumSwaps(vector<int>& nums) {
        
        int n = nums.size();

        int i = 0;
        int j = n - 1;

        int swaps = 0;

        while (i < j) {

            // i ko next zero par le jao
            while (i < j && nums[i] != 0)
                i++;

            // j ko next non-zero par le jao
            while (i < j && nums[j] == 0)
                j--;

            // swap karo
            if (i < j) {

                swap(nums[i], nums[j]);

                swaps++;

                i++;
                j--;
            }
        }

        return swaps;
    }
};