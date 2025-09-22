// class Solution {
// public:
//     // Function to count inversions using merge sort
//     long long marge_and_count(vector<int>& arr, int left, int mid, int right)
//     {
//         vector<int> temp;
//         int i = left, j = mid + 1;
//         long long inversion_count = 0;

//         // Merge two sorted halves
//         while (i <= mid && j <= right) {
//             if (arr[i] <= arr[j]) {
//                 temp.push_back(arr[i++]);
//             } else {
//                 temp.push_back(arr[j++]);
//                 // Jab arr[i] > arr[j] hota hai:
//                 // Matlab arr[i] aur arr[j] me inversion hai.
//                 // Kyunki left half sorted hai, to arr[i], arr[i+1], ... ,
//                 arr[mid] sab arr[j] se bade honge.
//                 // Total inversions = mid - i + 1
//                 inversion_count += (mid - i + 1);  // left wale jitne bache
//                 hai, sab greater honge
//             }
//         }

//         // Remaining elements
//         while (i <= mid) temp.push_back(arr[i++]);
//         while (j <= right) temp.push_back(arr[j++]);

//         // Copy back to original array
//         for (int k = left; k <= right; k++) {
//             arr[k] = temp[k - left];
//         }

//         return inversion_count;
//     }

//     long long merge_sort_and_count(vector<int>& arr, int left, int right) {
//         if (left >= right) return 0;

//         int mid = left + (right - left) / 2;
//         long long inversion_count = 0;

//         // Divide
//         inversion_count += merge_sort_and_count(arr, left, mid);
//         inversion_count += merge_sort_and_count(arr, mid + 1, right);

//         // Conquer
//         inversion_count += marge_and_count(arr, left, mid, right);

//         return inversion_count;
//     }

//     bool isIdealPermutation(vector<int>& nums) {
//         int n = nums.size();

//         // Step 1: count local inversions
//         long long local_inversion = 0;
//         for (int i = 0; i < n - 1; i++) {
//             if (nums[i] > nums[i + 1]) local_inversion++;
//         }

//         // Step 2: count global inversions using merge sort
//         vector<int> arr = nums;  // copy because merge sort modifies array
//         long long global_inversion = merge_sort_and_count(arr, 0, n - 1);

//         // Step 3: compare
//         return global_inversion == local_inversion;
//     }
// };

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();

        // Key insight: For global inversions to equal local inversions,
        // each element can be at most 1 position away from its correct position
        // In other words: abs(nums[i] - i) <= 1 for all i
        // Key Insight: For an array to have equal global and local inversions,
        // every global inversion must also be a local inversion. This means
        // that for any element at position i, it can only be "out of place" by
        // at most 1 position from where it should be in a sorted array.
        for (int i = 0; i < n; i++) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }

        return true;
    }
};
