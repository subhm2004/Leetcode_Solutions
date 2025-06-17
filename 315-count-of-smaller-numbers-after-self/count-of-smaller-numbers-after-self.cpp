class Solution {
public:
   void merge(vector<pair<int, int>>& nums_with_index, int low, int mid, int high,
               vector<int>& ans) {
                
        vector<pair<int, int>> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        int count = 0;

        while (i <= mid && j <= high) {
            if (nums_with_index[i].first > nums_with_index[j].first) {
                count++;
                temp[k++] = nums_with_index[j++];
            } else {
                ans[nums_with_index[i].second] += count;
                temp[k++] = nums_with_index[i++];
            }
        }

        while (i <= mid) {
            ans[nums_with_index[i].second] += count;
            temp[k++] = nums_with_index[i++];
        }

        while (j <= high) {
            temp[k++] = nums_with_index[j++];
        }

        for (int i = 0; i < temp.size(); ++i) {
            nums_with_index[low + i] = temp[i];
        }
    }
    void merge_Sort(vector<pair<int, int>>& nums_with_index, int low, int high,
                   vector<int>& ans) {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        merge_Sort(nums_with_index, low, mid, ans);
        merge_Sort(nums_with_index, mid + 1, high, ans);
        merge(nums_with_index, low, mid, high, ans);
    }
 
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> nums_with_index;

        for (int i = 0; i < n; ++i) {
            nums_with_index.push_back({nums[i], i});
        }

        merge_Sort(nums_with_index, 0, n - 1, ans);
        return ans;
    }
};
