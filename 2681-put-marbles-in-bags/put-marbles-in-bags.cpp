class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> maxHeap;  // Min sum nikalne ke liye max heap use kar rahe hain
        priority_queue<int, vector<int>, greater<int>> minHeap; // Max sum nikalne ke liye min heap use kar rahe hain

        // Adjacent pair sums calculate karke dono heaps me daal rahe hain
        for (int i = 0; i + 1 < weights.size(); ++i) {
            int sum = weights[i] + weights[i + 1];
            maxHeap.push(sum);
            minHeap.push(sum);

            // Sirf (k-1) elements hi heap me rakhne hain
            if (maxHeap.size() > k - 1) maxHeap.pop(); // MaxHeap me smallest k-1 elements rakhenge
            if (minHeap.size() > k - 1) minHeap.pop(); // MinHeap me largest k-1 elements rakhenge
        }

        long long minSum = 0, maxSum = 0;

        // MaxHeap se minSum calculate kar rahe hain (smallest k-1 elements ka sum)
        while (!maxHeap.empty()) {
            minSum += maxHeap.top();
            maxHeap.pop();
        }

        // MinHeap se maxSum calculate kar rahe hain (largest k-1 elements ka sum)
        while (!minHeap.empty()) {
            maxSum += minHeap.top();
            minHeap.pop();
        }

        return maxSum - minSum; // Final difference return kar rahe hain
    }
};
