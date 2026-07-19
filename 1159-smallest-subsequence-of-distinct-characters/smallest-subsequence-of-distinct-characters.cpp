class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> last_idx;
        unordered_map<char, bool> visited;

        // Har character ki last occurrence store karo
        for (int i = 0; i < s.size(); i++)
            last_idx[s[i]] = i;

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (visited[ch])
                continue;

            while (!ans.empty() && ans.back() > ch && last_idx[ans.back()] > i) {

                visited[ans.back()] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch] = true;
        }

        return ans;
    }
};