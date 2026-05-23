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

            // duplicates
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {

                // check manually before shrinking
                if (l < n - 1 && nums[l] > nums[l + 1])
                    return l + 1;

                l++;
                r--;
            }

            // left sorted
            else if (nums[mid] >= nums[l]) {
                l = mid + 1;
            }

            // right sorted
            else {
                r = mid - 1;
            }
        }

        return 0;
    }

    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int pivot = find_Pivot(nums);

        // search right half
        if (binary_Search(nums, pivot, n - 1, target) != -1)
            return true;

        // search left half
        if (binary_Search(nums, 0, pivot - 1, target) != -1)
            return true;

        return false;
    }
};