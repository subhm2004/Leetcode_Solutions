class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int curr_max_prod = nums[0];
        int curr_min_prod = nums[0];
        int max_prod = nums[0];

        for(int i = 1; i < n ; i++){

            if(nums[i] < 0)  swap(curr_max_prod, curr_min_prod);

            curr_max_prod = max(nums[i], curr_max_prod * nums[i]);
            curr_min_prod = min(nums[i], curr_min_prod * nums[i]);

            max_prod = max(max_prod, curr_max_prod);
        }

        return max_prod;
    }
};