class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // ascending part
            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            }
            // descending part (or at peak)
            else {
                end = mid;
            }
        }

        // start == end == peak index
        return start;
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
