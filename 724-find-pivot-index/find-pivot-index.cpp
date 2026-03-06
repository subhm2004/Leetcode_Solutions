class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total_sum = 0;
        for(int x : nums) {
            total_sum += x;
        }
        // total_sum = accumulate(nums.begin(),nums.end(),0);

        int left_sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            // total sum = left_sum + pivot idx element(nums[i]) + right_sum
            // to ab rearrange krke aata hai 
            // right_sum = total sum - left_sum - nums[i]
            int right_sum = total_sum - left_sum - nums[i];

            if(left_sum == right_sum) {
                return i;
            }

            left_sum += nums[i];
        }

        return -1;
    }
};