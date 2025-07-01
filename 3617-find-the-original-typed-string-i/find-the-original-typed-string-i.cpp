class Solution {
public:
    int dfs(const vector<int>& groupSizes, int i, bool removed) {
        if (i == groupSizes.size()) return 1;

        int total = 0;

        // Case 1: Don't remove anything from this group
        total += dfs(groupSizes, i + 1, removed);

        // Case 2: Remove 1 character from this group (only if not already removed before)
        if (!removed && groupSizes[i] > 1) {
            total += (groupSizes[i] - 1) * dfs(groupSizes, i + 1, true);
        }

        return total;
    }

    int possibleStringCount(string word) {
        vector<int> groupSizes;
        int n = word.size();

        // Step 1: Group consecutive characters
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;
            groupSizes.push_back(j - i);
            i = j;
        }

        return dfs(groupSizes, 0, false); // Ab tak koi bhi group me se character remove nahi kiya gaya isliye humne false pass kiya hai question me
    }
};


