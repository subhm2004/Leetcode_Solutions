class Solution {
public:
     void helper(vector<int>& nums, vector<int>& sorted, int i, int left, int right) {
        // Base case: agar index array ke size se bahar chala gaya, to stop karo
        if (i >= nums.size()) return;
        
        if (i % 2 == 0) {
            // Agar index even hai, to left (small elements) se value lo
            nums[i] = sorted[left];
            
            // Ab agle index ke liye recursion chalao
            helper(nums, sorted, i + 1, left - 1, right);
        } else {
            // Agar index odd hai, to right (big elements) se value lo
            nums[i] = sorted[right];
            
            // Ab agle index ke liye recursion chalao
            helper(nums, sorted, i + 1, left, right - 1);
        }
    }
    
    void wiggleSort(vector<int>& nums) {
        // Step 1: Sort karo
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        // Step 2: Left half aur right half ke pointers banao
        int left = (nums.size() + 1) / 2 - 1; // chhote half ka last index
        int right = nums.size() - 1;          // bade half ka last index
        
        // Step 3: Recursion start karo index 0 se
        helper(nums, sorted, 0, left, right);
    }
};
