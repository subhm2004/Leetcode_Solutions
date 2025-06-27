class Solution {
public:
    string ans = "";

    //  Check if sub * k is a subsequence of s
    bool isSubsequence(string& s, string& sub, int k) {
        int i = 0, j = 0;
        int L = sub.length(), n = s.length();

        while (i < n && j < k * L) {
            if (s[i] == sub[j % L])
                j++;
            i++;
        }
        return j == k * L;
    }

    // Backtracking with pruning
    void backtracking(string& s, string& curr, vector<bool>& can_Use,
                      vector<int>& required_Freq, int k, int max_Len) {
        if (curr.length() > max_Len) return;

        // Update answer only if current is valid
        if (((curr.length() > ans.length()) ||
             (curr.length() == ans.length() && curr > ans)) &&
            isSubsequence(s, curr, k)) {
            ans = curr;
        }

        //  Optimization : Answer jaldi mil sake isliye pehle bade letters try karo (lexicographically bade chahiye hume wo peeche se hi milege)
        for (int i = 25; i >= 0; i--) {
            if (!can_Use[i] || required_Freq[i] == 0)
                continue;

            // DO
            char ch = i + 'a';
            curr.push_back(ch);
            required_Freq[i]--;

            // EXPLORE
            backtracking(s, curr, can_Use, required_Freq, k, max_Len);

            // UNDO
            curr.pop_back();
            required_Freq[i]++;

            // Optimization : Best length mil gayi hai, ab aur check karne ki zarurat nahi
            if (ans.length() == max_Len) return;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        vector<bool> can_Use(26, false);
        vector<int> required_Freq(26, 0);
        int max_Len = s.size() / k; // subsequence ki maximum length ye ho skti hai kyoki max_Len * k <= s.length

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                can_Use[i] = true;
                required_Freq[i] = freq[i] / k;
            }
        }

        string curr = "";
        backtracking(s, curr, can_Use, required_Freq, k, max_Len);
        return ans;
    }
};
