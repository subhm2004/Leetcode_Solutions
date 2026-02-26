class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int max_sum = INT_MIN;
    
        for (int right = 0; right < n; right++) {
            sum += nums[right];  // expand window
    
            // jab window ka size k ho jaye
            if (right - left + 1 == k) {
                max_sum = max(max_sum, sum);
    
                sum -= nums[left];  // shrink window
                left++;
            }
        }
    
        return  1.0 * max_sum / k;
    }
};