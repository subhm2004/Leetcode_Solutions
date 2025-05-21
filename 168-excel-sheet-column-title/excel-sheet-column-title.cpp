class Solution {
public:
    string helper(int columnNumber) {
        if (columnNumber == 0)
            return "";

        columnNumber--; // convert to 0-based index
        char ch = 'A' + (columnNumber % 26);

        return ch + helper(columnNumber / 26);
    }
    string convertToTitle(int columnNumber) {
        string ans = helper(columnNumber);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};