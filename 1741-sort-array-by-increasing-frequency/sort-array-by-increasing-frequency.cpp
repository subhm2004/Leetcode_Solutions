class Solution {
public:
    // Function to sort the vector based on frequency of elements
    vector<int> frequencySort(vector<int>& nums) {
        // Unordered map to count the frequency of each element
        unordered_map<int, int> count;
        
        // Count the frequency of each element in the vector
        for (int v : nums) count[v]++;
        
        // Sort the vector with a custom comparator(lambda function)
        sort(nums.begin(), nums.end(), [&](auto& a, auto& b) {
            // If frequencies are equal, sort by element value in descending order
            // Otherwise, sort by frequency in ascending order
            return count[a] == count[b] ? a > b : count[a] < count[b];
        });
        
        // Return the sorted vector
        return nums;
    }
};
