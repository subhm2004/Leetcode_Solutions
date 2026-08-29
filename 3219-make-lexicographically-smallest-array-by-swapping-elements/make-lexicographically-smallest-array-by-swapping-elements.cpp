class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> result(n); // Final result array banane ke liye
        vector<pair<int, int>> indexedNums; // (value, index) ka pair banayenge

        // Har number ko uske index ke saath pair karke vector mein daal do
        for (int i = 0; i < n; ++i) {
            indexedNums.push_back({nums[i], i});
        }

        // Value ke basis par sort kar lo (ascending order mein)
        sort(indexedNums.begin(), indexedNums.end());

        int i = 0;
        while (i < n) {
            int j = i;

            // Group banao jahan tak consecutive values ka difference `limit` ke andar ho
            while (j + 1 < n && indexedNums[j + 1].first - indexedNums[j].first <= limit) {
                ++j;
            }

            // Group ke indices ko extract karo
            vector<int> group;
            for (int k = i; k <= j; ++k) {
                group.push_back(indexedNums[k].second);
            }

            // Indices ko sort kar lo taaki lexicographically smallest result aaye
            sort(group.begin(), group.end());

            // Group ke har index par original value place karo
            for (int k = 0; k < group.size(); ++k) {
                result[group[k]] = indexedNums[i + k].first;
            }

            // Next group par move karo
            i = j + 1;
        }

        return result;
    }
};
