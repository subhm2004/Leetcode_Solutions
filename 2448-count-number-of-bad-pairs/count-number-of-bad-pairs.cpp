// class Solution {
//  public:
//  ll countBadPairs(vector<int>& nums) {
//     long ans = 0;
//     unordered_map<int, int> count;  // (nums[i] - i)

//     for (int i = 0; i < nums.size(); ++i)
//       //     count[nums[i] - i] := the number of good pairs
//       // i - count[nums[i] - i] := the number of bad pairs
//       ans += i - count[nums[i] - i]++;

//     return ans;
//   }
// };

// Good Pair nums[i]−i==nums[j]−j

using ll = long long;
class Solution {
public:
    ll countBadPairs(vector<int>& nums) {
        int n = nums.size();
        ll totalPairs = (ll)n * (n - 1) / 2;
        unordered_map<int, int> count;
        ll goodPairs = 0;

        for (int i = 0; i < nums.size(); ++i)
            goodPairs += count[nums[i] - i]++;

        return totalPairs - goodPairs;
    }
};
