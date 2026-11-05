class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        auto isValid = [&](int a) -> bool {
            int left = 0, right = arr2.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (abs(arr2[mid] - a) <= d) {
                    return false;
                }
                if (arr2[mid] < a - d) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return true;
        };
        for (int i : arr1) {
            if (isValid(i)) {
                count++;
            }
        }
        return count;
    }
};
