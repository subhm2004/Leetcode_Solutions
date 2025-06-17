class Solution {
public:
    void merge(vector<pair<int, int>>& arr, int left, int mid, int right, vector<int>& counts) {
        vector<pair<int, int>> temp;
        int i = left;
        int j = mid + 1;
        int right_count = 0;

        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                // Right element is smaller → move it and count
                temp.push_back(arr[j]);
                right_count++;
                j++;
            } else {
                // Count how many smaller on right side
                counts[arr[i].second] += right_count;
                temp.push_back(arr[i]);
                i++;
            }
        }

        // Remaining elements in left part
        while (i <= mid) {
            counts[arr[i].second] += right_count;
            temp.push_back(arr[i]);
            i++;
        }

        // Remaining elements in right part
        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy back to original array
        for (int i = 0; i < temp.size(); ++i) {
            arr[left + i] = temp[i];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& counts) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid + 1, right, counts);
        merge(arr, left, mid, right, counts);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> arr;  // {num, index}
        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, counts);
        return counts;
    }
};
