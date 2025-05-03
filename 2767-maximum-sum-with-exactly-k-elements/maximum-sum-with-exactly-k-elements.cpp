class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;  // Max-heap
        
        // Insert all elements of nums into the heap
        for (int num : nums) {
            maxHeap.push(num);
        }
        
        int score = 0;
        
        // Perform the operation k times
        while (k > 0) {
            int maxElement = maxHeap.top();  // Get the largest element
            maxHeap.pop();  // Remove it from the heap
            
            score += maxElement;  // Add its value to the score
            maxHeap.push(maxElement + 1);  // Insert maxElement + 1 into the heap
            
            k--;  // Decrease k after each operation
        }
        
        return score;
    }
};