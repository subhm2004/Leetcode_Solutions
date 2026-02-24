class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total_sum = 0;
        for(int x : nums) {
            total_sum += x;
        }

        int left_sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            
            int right_sum = total_sum - left_sum - nums[i];

            if(left_sum == right_sum) {
                return i;
            }

            left_sum += nums[i];
        }

        return -1;
    }
};