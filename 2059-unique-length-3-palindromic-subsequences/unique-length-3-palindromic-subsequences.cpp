class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    int result = 0;
    vector<int> first(26, -1);
    vector<int> last(26, -1);

    for (int i = 0; i < s.size(); ++i) {
      int index = s[i] - 'a';
      if (first[index] == -1) {
        first[index] = i;
      }
      last[index] = i;
    }

    for (int i = 0; i < 26; ++i) {
      if (first[i] != -1 && first[i] < last[i]) {
        vector<bool> middle(26, false);
        for (int j = first[i] + 1; j < last[i]; ++j) {
          middle[s[j] - 'a'] = true;
        }
        int unique_count = 0;
        for (int k = 0; k < 26; ++k) {
          if (middle[k]) {
            unique_count++;
          }
        }
        result += unique_count;
      }
    }

    return result;
  }
};