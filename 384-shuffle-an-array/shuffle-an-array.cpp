class Solution {
public:
    vector<int> original;
    vector<int> current;

    Solution(vector<int>& nums) {
        original = nums;
        current = nums;
    }
    
    vector<int> reset() {
        current = original;
        return current;
    }
    
    vector<int> shuffle() {
        current = original;
        int n = current.size();
        for (int i = 0; i < n; i++) {
            int j = rand() % (i + 1);  
            swap(current[i], current[j]);
        }
        return current;
    }
};
