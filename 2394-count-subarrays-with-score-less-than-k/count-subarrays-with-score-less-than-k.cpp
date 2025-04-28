typedef long long ll;
class Solution {
public:
    ll countSubarrays(vector<int>& nums, ll k) {
        ll ans = 0, currSum = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            currSum += nums[r];
            while (currSum * (r - l + 1) >= k) {
                currSum -= nums[l];
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
