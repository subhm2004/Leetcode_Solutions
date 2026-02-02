using ll = long long;
class Solution {
public:
ll diff;
    ll ans;

    void merge(vector<ll>& nums, int low, int mid, int high) {

        // count valid pairs
        int i = low;
        for (int j = mid + 1; j <= high; j++) {
            while (i <= mid && nums[i] <= nums[j] + diff)
                i++;
            // nums[low ... i-1] valid hai to i - 1 - low +1 = i - low 
            ans += (i - low);
        }

        // normal merge (sorting)
        vector<ll> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while (left <= mid)
            temp.push_back(nums[left++]);
        while (right <= high)
            temp.push_back(nums[right++]);

        for (int k = 0; k < (int)temp.size(); k++)
            nums[low + k] = temp[k];
    }
void mergeSort(vector<ll>& nums, int low, int high) {
        if (low >= high)
            return;

        int mid = (low + high) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
            this->diff = diff;
            ans = 0;

            vector<ll> A(n);
            for (int i = 0; i < n; i++)
                A[i] = (ll)nums1[i] - nums2[i];

            mergeSort(A, 0, n - 1);

            return ans;
    }
};





