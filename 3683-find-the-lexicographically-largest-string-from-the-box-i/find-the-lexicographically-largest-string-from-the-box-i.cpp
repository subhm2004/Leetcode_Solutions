class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if( numFriends == 1)
            return word;

        string ans;

        int longest_Possible = n - (numFriends - 1);

        for(int i = 0; i < n; i++) {
            int can_Take_Length = min(longest_Possible, n-i);

            ans = max(ans, word.substr(i, can_Take_Length));
        }

        return ans;
    }
};
