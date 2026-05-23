class Solution {
public:

    bool check(vector<int>& nums) {

        int n = nums.size();

        int pivot = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] > nums[(i + 1) % n]) {
                pivot++;
            }
            if(pivot > 1) return false;
        }

        return true;
    }
};