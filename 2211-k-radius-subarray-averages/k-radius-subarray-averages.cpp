class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    int windowSize = 2 * k + 1; // Yeh sliding window ka size hoga
    vector<int> ans(n, -1); // Default -1 se fill kar diya

    // Agar window size poore array se bada hai, toh directly return kar do
    if (windowSize > n) return ans;

    long long windowSum = 0;

    // Pehle window ka sum calculate kar lo
    for (int i = 0; i < windowSize; ++i)
      windowSum += nums[i];

    // Sliding window lagao
    for (int i = k; i + k < n; ++i) {
      ans[i] = windowSum / windowSize; // Average store karo
      if (i + k + 1 < n) // Agla window shift hone par update karo
        windowSum += nums[i + k + 1] - nums[i - k];
    }

    return ans;
  }
};
