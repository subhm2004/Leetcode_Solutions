class Solution {
public:
    // Ye function LIS ka length aur count return karega
    pair<int, int> find_LIS_length_and_count(const vector<int>& arr, int curr, int prev, 
                                          vector<vector<int>>& dpLength, 
                                          vector<vector<int>>& dpCount) {
        // Base case: agar pura array traverse kar liya, toh {0, 1} return karo
        if (curr >= arr.size()) {
            return {0, 1}; // Length = 0, aur ek valid LIS count = 1
        }

        // Agar DP table me answer stored hai toh wahi return kar do
        if (dpLength[curr][prev + 1] != -1) {
            return {dpLength[curr][prev + 1], dpCount[curr][prev + 1]};
        }

        int includeLength = 0, includeCount = 0;
        // Agar current element LIS me include kar sakte hai toh use karo
        if (prev == -1 || arr[curr] > arr[prev]) {
            auto [len, cnt] = find_LIS_length_and_count(arr, curr + 1, curr, dpLength, dpCount);
            includeLength = len + 1;
            includeCount = cnt;
        }

        // Current element ko exclude karke bhi LIS nikalne ka try karo
        auto [excludeLength, excludeCount] = find_LIS_length_and_count(arr, curr + 1, prev, dpLength, dpCount);

        // Maximum length ka LIS choose karo
        if (includeLength > excludeLength) {
            dpLength[curr][prev + 1] = includeLength;
            dpCount[curr][prev + 1] = includeCount;
        } else if (includeLength < excludeLength) {
            dpLength[curr][prev + 1] = excludeLength;
            dpCount[curr][prev + 1] = excludeCount;
        } else {
            dpLength[curr][prev + 1] = includeLength;
            dpCount[curr][prev + 1] = includeCount + excludeCount; // Dono ko add kar do
        }

        return {dpLength[curr][prev + 1], dpCount[curr][prev + 1]};
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Agar empty array hai toh LIS count = 0

        // DP tables initialize kar rahe hain
        vector<vector<int>> dpLength(n, vector<int>(n + 1, -1));  
        vector<vector<int>> dpCount(n, vector<int>(n + 1, -1)); 

        // LIS ka length aur count dono le rahe hain
        auto [maxLength, totalCount] = find_LIS_length_and_count(nums, 0, -1, dpLength, dpCount);

        return totalCount; // Bas LIS ke total count ka second part return kar do
    }
};
