class Solution {
 public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> ans;
    // Min heap bana rahe hain taaki hum k largest elements ko efficiently store kar sakein
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    // Loop karke nums array ke elements ko min heap mein daal rahe hain
    for (int i = 0; i < nums.size(); i++) {
      minHeap.push({nums[i], i});
      // Agar heap mein elements ki count k se zyada ho jaye, to pop karte hain smallest element ko
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    // Ab selected vector mein k largest elements ko unke index ke saath store kar rahe hain
    vector<pair<int, int>> selected;
    while (!minHeap.empty()) {
      selected.push_back(minHeap.top());
      minHeap.pop();
    }

    // Ab selected elements ko unke index ke according sort kar rahe hain taaki original order maintain ho sake
    sort(selected.begin(), selected.end(), [](const auto& a, const auto& b) {
      return a.second < b.second;
    });

    // Final subsequence mein k elements ko daal rahe hain
    for (const auto& p : selected) {
      ans.push_back(p.first);
    }

    // Return karte hain final subsequence
    return ans;
  }
};
