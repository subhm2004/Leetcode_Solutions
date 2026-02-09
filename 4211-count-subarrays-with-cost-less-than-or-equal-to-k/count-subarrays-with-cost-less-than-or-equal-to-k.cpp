class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        multiset<long long> ms;

        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {

            ms.insert(nums[right]);

            // window ko valid banate hai 
            while (!ms.empty()) {

                long long mini = *ms.begin();
                long long maxi = *ms.rbegin();

                long long cost = (maxi - mini) * (right - left + 1LL);

                if (cost > k) {
                    ms.erase(ms.find(nums[left]));
                    left++;
                }
                else
                    break;
            }

            ans += (right - left + 1);
        }

        return ans;
    
    }
};