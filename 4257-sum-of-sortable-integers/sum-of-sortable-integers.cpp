class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        // Precompute: for each position i, does nums[i] == sorted_nums[i]?
        // Precompute descent positions in nums (where nums[i] > nums[i+1])
        // For a block to be a valid rotation of its sorted version:
        //   1. Same multiset as sorted block
        //   2. At most one "wrap descent" in the circular view of block
        
        int ans = 0;
        
        for(int k = 1; k <= n; k++) {
            if(n % k != 0) continue;
            
            bool is_valid = true;
            
            for(int i = 0; i < n; i += k) {
                // Check 1: multiset match using sorted block comparison
                // Since sorted_nums is globally sorted and blocks partition it,
                // we need block's sorted version == sorted_nums[i..i+k-1]
                
                // O(k log k) — sort block and compare
                // But we can do better with the rotation insight:
                
                // A sorted array is a rotation of block iff:
                //   - block has exactly one descent (circular), OR block is already sorted
                //   - AND multiset matches sorted_nums[i..i+k-1]
                
                int descents = 0;
                int rotation_start = 0; // where sorted order begins
                
                for(int j = 0; j < k; j++) {
                    int cur = nums[i + j];
                    int nxt = nums[i + (j + 1) % k];
                    
                    if(cur > nxt) {
                        descents++;
                        rotation_start = j + 1; // sorted block starts after descent
                    }
                }
                
                // More than 1 descent = can't be rotation of sorted array
                if(descents > 1) {
                    is_valid = false;
                    break;
                }
                
                // Check multiset: rotated block should equal sorted_nums[i..i+k]
                // If descents <= 1, verify the rotation matches sorted target
                bool match = true;
                for(int j = 0; j < k; j++) {
                    if(nums[i + (rotation_start + j) % k] != sorted_nums[i + j]) {
                        match = false;
                        break;
                    }
                }
                
                if(!match) {
                    is_valid = false;
                    break;
                }
            }
            
            if(is_valid) ans += k;
        }
        
        return ans;
    }
};
