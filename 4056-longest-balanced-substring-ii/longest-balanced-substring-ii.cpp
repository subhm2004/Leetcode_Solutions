class Solution {
public:
    int n;
    string s;

    // case 1 : only one character
    int solve_one_char() {
        int max_len = 1;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            // ab jab j stop hoga to wo first invalid index hoga
            // range = [i , j) == [i , j-1] , length = j - i
            max_len = max(max_len, j - i);
            i = j;
        }

        return max_len;
    }

    // case 2 : exactly two characters  
    int solve_two_char(char x, char y, char bad_char) {
        int max_len = 0;
        int diff = 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {

            // forbidden character → break the segment
            if (s[i] == bad_char) {
                diff = 0;
                mp.clear();
                mp[0] = i;
                continue;
            }
            // diff = count(x) - count(y)
            if (s[i] == x) diff++;
            if (s[i] == y) diff--;

            if (mp.find(diff) != mp.end())
                max_len = max(max_len, i - mp[diff]);
            else
                mp[diff] = i;
        }

        return max_len;
    }

    // case 3 : all three characters
    int solve_three_Char() {
        int max_len = 0;

        int A = 0, B = 0, C = 0;

        map<pair<int,int>, int> mp;
        mp[{0,0}] = -1;

        for (int i = 0; i < n; i++) {

            if (s[i] == 'a') A++;
            else if (s[i] == 'b') B++;
            else C++;

            int d1 = A - B;
            int d2 = A - C;

            pair<int,int> state = {d1, d2};

            if (mp.find(state) != mp.end())
                max_len = max(max_len, i - mp[state]);
            else
                mp[state] = i;
        }

        return max_len;
    }

    int longestBalanced(string s) {
        this->s = s;
        n = s.size();

        int ans = 1;

        ans = max(ans, solve_one_char());

        ans = max(ans, solve_two_char('a','b','c'));
        ans = max(ans, solve_two_char('a','c','b'));
        ans = max(ans, solve_two_char('b','c','a'));

        ans = max(ans, solve_three_Char());

        return ans;
    }
};
