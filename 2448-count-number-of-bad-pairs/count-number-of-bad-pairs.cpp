// Good Pair nums[i]−i ==n ums[j]−j

using ll = long long;
class Solution {
public:
    ll countBadPairs(vector<int>& nums) {
        int n = nums.size();

        ll total_pairs = (ll)n * (n - 1) / 2; // nC2 total pairs
        
        unordered_map<int, int> count;

        ll good_pairs = 0;

        for (int i = 0; i < nums.size(); ++i)
            good_pairs += count[nums[i] - i]++;

        return total_pairs - good_pairs;
    }
};