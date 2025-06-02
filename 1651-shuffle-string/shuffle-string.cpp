class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result(s.length(), ' ');  // Initialize a result string with the same length
        for (int i = 0; i < s.length(); ++i) {
            result[indices[i]] = s[i];   // Place each character at the correct index
        }
        return result;
    }
};
