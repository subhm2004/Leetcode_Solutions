// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//     }
// };
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap; // Min-heap

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // pop smallest if size exceeds k
            }
        }

        return minHeap.top(); // kth largest
    }
};
