class MergeSort {
public:
    void sort(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }

private:
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = 0; i < temp.size(); ++i) {
            nums[low + i] = temp[i];
        }
    }
};

class QuickSort {
public:
    void sort(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }

private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);
            quickSort(nums, low, pi - 1);
            quickSort(nums, pi + 1, high);
        }
    }
};

class HeapSort {
public:
    void sort(vector<int>& nums) {
        int n = nums.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // Heap sort
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

private:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
};

class CountSort {
public:
    void sort(vector<int>& nums) {
        if (nums.empty()) return;

        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int range = maxVal - minVal + 1;

        vector<int> count(range, 0);

        // Count frequency of each number
        for (int num : nums) {
            count[num - minVal]++;
        }

        // Overwrite original array with sorted values
        int index = 0;
        for (int i = 0; i < range; ++i) {
            while (count[i]-- > 0) {
                nums[index++] = i + minVal;
            }
        }
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort sorter;
        // QuickSort sorter;
        // HeapSort sorter;
        // CountSort sorter;

        sorter.sort(nums);
        return nums;
    }
};

