class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] > arr[mid + 1]) {
                right = mid ;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         for (int i = 1; i < arr.size() - 1; ++i) {
//             if (arr[i] > arr[i + 1]) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
