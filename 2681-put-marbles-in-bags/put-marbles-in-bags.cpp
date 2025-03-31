class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
    priority_queue<int> maxHeap; // Max heap for minSum calculation
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for maxSum calculation
    
    // Compute adjacent pair sums
    for (int i = 0; i + 1 < weights.size(); ++i) {
      int sum = weights[i] + weights[i + 1];
      maxHeap.push(sum);
      minHeap.push(sum);

      // Keep only k-1 elements in heaps
      if (maxHeap.size() > k - 1) maxHeap.pop();
      if (minHeap.size() > k - 1) minHeap.pop();
    }

    long long minSum = 0, maxSum = 0;
    
    // Compute minSum from maxHeap (smallest k-1 elements)
    while (!maxHeap.empty()) {
      minSum += maxHeap.top();
      maxHeap.pop();
    }

    // Compute maxSum from minHeap (largest k-1 elements)
    while (!minHeap.empty()) {
      maxSum += minHeap.top();
      minHeap.pop();
    }

    return maxSum - minSum;
  }
};
