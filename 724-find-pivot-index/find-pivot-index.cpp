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


/*
class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();

        // prefix_sum[i] = sum of elements from index 0 to i-1
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_sum[i + 1] = prefix_sum[i] + arr[i];

        int total_sum = prefix_sum[n];

        for (int i = 0; i < n; i++) {
            int left_sum  = prefix_sum[i];              // sum of [0, i-1]
            int right_sum = total_sum - prefix_sum[i + 1]; // sum of [i+1, n-1]

            if (left_sum == right_sum)
                return i;
        }

        return -1;
    }
};

*/