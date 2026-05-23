class Solution {
public:

    int binary_Search(vector<int>& nums, int l, int r, int target) {

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    int find_Pivot(vector<int>& nums) {

        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            // pivot found
            if (mid < n - 1 && nums[mid] > nums[mid + 1])
                return mid + 1;

            // left part sorted
            if (nums[l] <= nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return 0;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int pivot = find_Pivot(nums);

        // target right sorted half me hai
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binary_Search(nums, pivot, n - 1, target);
        }

        // target left sorted half me hai
        return binary_Search(nums, 0, pivot - 1, target);
    }
};