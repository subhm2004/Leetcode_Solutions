class Solution {
public:
    //  Check if sub * k is a subsequence of s
    bool is_subsequence(string& s, string& sub, int k) {
        int i = 0, j = 0;
        int L = sub.length(), n = s.length();

        while (i < n && j < k * L) {
            if (s[i] == sub[j % L])
                j++;
            i++;
        }
        return j == k * L;
    }

    //  BFS function to build all possible valid subsequences
    string bfs(string& s, int k) {
    queue<string> q;
    q.push("");
    string ans = "";

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        for (char ch = 'z'; ch >= 'a'; --ch) {
            string next = curr + ch;

            if (is_subsequence(s, next, k)) {
                q.push(next); 
                if (next.size() > ans.size() || (next.size() == ans.size() && next > ans)) {
                    ans = next;
                }
            }
        }
    }

    return ans;
}


    string longestSubsequenceRepeatedK(string s, int k) {
        return bfs(s, k);
    }
};
