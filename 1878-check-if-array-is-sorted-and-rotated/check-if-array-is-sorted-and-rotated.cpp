class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int peak = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                peak++;
            }
        }

        return peak <= 1;
    }
};


// class Solution {     agar mujeh k times roate krna hota array to 
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n; // Handle cases where k > n

//         // Reverse entire array
//         reverse(nums.begin(), nums.end());

//         // Reverse first k elements
//         reverse(nums.begin(), nums.begin() + k);

//         // Reverse remaining n-k elements
//         reverse(nums.begin() + k, nums.end());
//     }
// };
