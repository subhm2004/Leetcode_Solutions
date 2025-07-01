class Solution {
public:
    int dfs(const vector<int>& groupSizes, int index, bool removed) {
        if (index == groupSizes.size()) {
            return 1;
        }

        int total = 0;

        total += dfs(groupSizes, index + 1, removed);

        if (!removed && groupSizes[index] > 1) {
            for (int i = 1; i < groupSizes[index]; ++i) {
                total += dfs(groupSizes, index + 1, true);
            }
        }

        return total;
    }

    int possibleStringCount(string word) {
        vector<int> groupSizes;
        int n = word.size();

        int i = 0;
        while (i < n) {
            char currentChar = word[i];
            int count = 0;

            while (i < n && word[i] == currentChar) {
                count++;
                i++;
            }
            groupSizes.push_back(count);
        }

        return dfs(groupSizes, 0, false);
    }
};
