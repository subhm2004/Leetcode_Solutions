class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        
        arr1.push_back(nums[0]);   // 1st operation
        arr2.push_back(nums[1]);   // 2nd operation
        
        // ith operation (0-indexed me i = 2 se start)
        for (int i = 2; i < n; i++) {
            if (arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        
        // concatenate arr1 + arr2
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};