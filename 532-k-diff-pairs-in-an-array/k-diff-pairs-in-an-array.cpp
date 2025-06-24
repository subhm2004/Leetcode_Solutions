class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // Edge case: If k is negative, absolute difference cannot be negative
        // So return 0 immediately
        if (k < 0) return 0;
        
        // Step 1: Create frequency map to count occurrences of each number
        // This helps us:
        // 1. Handle duplicates efficiently
        // 2. Quickly check if a target number exists
        unordered_map<int, int> freq;
        
        // Populate frequency map - count how many times each number appears
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Initialize counter for valid k-diff pairs
        int count = 0;
        
        // Step 3: Iterate through each unique number in our frequency map
        // Using structured binding (C++17 feature) to get both key and value
        for (auto& [num, cnt] : freq) {
            
            // Case 1: k = 0 (Special case)
            // We need pairs where nums[i] == nums[j] but i != j
            // This means the same number must appear at least twice
            if (k == 0) {
                // If current number appears more than once, we can form pairs
                // Example: [1,1,1] can form pairs (1,1) with different indices
                if (cnt > 1) {
                    count++;  // Count this as one unique pair type
                }
            } 
            // Case 2: k > 0 (Normal case)
            // We need pairs where |nums[i] - nums[j]| = k
            else {
                // Since we want |a - b| = k, we can have:
                // 1. a - b = k  → b = a - k
                // 2. b - a = k  → b = a + k
                // 
                // To avoid counting same pair twice (like (1,3) and (3,1)),
                // we only check for (num + k) existence
                // This ensures we count each unique pair exactly once
                
                if (freq.count(num + k)) {
                    count++;  // Found a valid pair: (num, num+k)
                }
                
                // Why we don't check (num - k):
                // When we process (num - k) later in iteration,
                // we'll check for ((num-k) + k) = num, which covers the same pair
            }
        }
        
        // Return total count of unique k-diff pairs
        return count;
    }
};

/*
DETAILED WALKTHROUGH WITH EXAMPLE:
Input: nums = [3,1,4,1,5], k = 2

Step 1: Build frequency map
nums = [3,1,4,1,5]
After processing all elements:
freq = {3:1, 1:2, 4:1, 5:1}

Step 2: Process each unique number
count = 0, k = 2

Iteration 1: num = 3, cnt = 1
- k != 0, so go to else branch
- Check if freq.count(3 + 2) = freq.count(5) exists
- freq[5] exists (value = 1)
- count++ → count = 1
- Pair found: (3,5) where |3-5| = 2 ✓

Iteration 2: num = 1, cnt = 2  
- k != 0, so go to else branch
- Check if freq.count(1 + 2) = freq.count(3) exists
- freq[3] exists (value = 1)  
- count++ → count = 2
- Pair found: (1,3) where |1-3| = 2 ✓

Iteration 3: num = 4, cnt = 1
- k != 0, so go to else branch  
- Check if freq.count(4 + 2) = freq.count(6) exists
- freq[6] does not exist
- No increment, count remains 2

Iteration 4: num = 5, cnt = 1
- k != 0, so go to else branch
- Check if freq.count(5 + 2) = freq.count(7) exists  
- freq[7] does not exist
- No increment, count remains 2

Final answer: count = 2

The two unique k-diff pairs are:
1. (1,3) with |1-3| = 2
2. (3,5) with |3-5| = 2

TIME COMPLEXITY: O(n) 
- O(n) to build frequency map
- O(n) to iterate through unique numbers (at most n unique numbers)

SPACE COMPLEXITY: O(n)
- O(n) for frequency map storage
*/