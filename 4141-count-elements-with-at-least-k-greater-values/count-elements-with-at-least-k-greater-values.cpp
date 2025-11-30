class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return n;   // everyone qualifies

        // maintain top k largest values
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (int x : nums) {
            if (minHeap.size() < k) {
                minHeap.push(x);
            } else if (x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
        }

        // now minHeap.top() = kth largest element
        int kth_largest = minHeap.top();

        // count elements strictly smaller than kth_largest
        int count = 0;
        for (int x : nums) {
            if (x < kth_largest) count++;
        }

        return count;
    }
};
