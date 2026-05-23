class Solution {
public:

    int findMin(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        int ans = nums[0];

        while (l <= r) {

            int mid = l + (r - l) / 2;

            // duplicates
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {

                ans = min(ans, nums[mid]);

                l++;
                r--;
            }

            // left half sorted
            else if (nums[l] <= nums[mid]) {

                ans = min(ans, nums[l]);

                l = mid + 1;
            }

            // right half sorted
            else {

                ans = min(ans, nums[mid]);

                r = mid - 1;
            }
        }

        return ans;
    }
};