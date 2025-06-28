class Solution {
 public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    for (int i = 0; i < nums.size(); i++) {
      minHeap.push({nums[i], i});
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    vector<pair<int, int>> selected;
    while (!minHeap.empty()) {
      selected.push_back(minHeap.top());
      minHeap.pop();
    }

    sort(selected.begin(), selected.end(), [](const auto& a, const auto& b) {
      return a.second < b.second;
    });

    for (const auto& [val, idx] : selected) {
      ans.push_back(val);
    }

    return ans;
  }
};
