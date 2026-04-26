class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;

        // peak nikalte hai 
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peak = i;
                break;
            }
        }

        long long ascending_sum = 0, descending_sum = 0;

        for (int i = 0; i <= peak; i++) {
            ascending_sum += nums[i];
        }

        for (int i = peak; i < n; i++) {
            descending_sum += nums[i];
        }

        if (ascending_sum > descending_sum) return 0;
        if (descending_sum > ascending_sum) return 1;
        return -1;
    }
};
 void fastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
