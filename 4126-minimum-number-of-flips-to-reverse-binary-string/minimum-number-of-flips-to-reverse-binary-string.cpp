class Solution {
public:
    int minimumFlips(int n) {
        string s = bitset<32>(n).to_string();

        // leading zeros remove
        int pos = s.find('1');
        s = s.substr(pos);

        int i = 0;
        int j = s.size() - 1;
        int ans = 0;

        while (i < j) {
            if (s[i] != s[j])
                ans += 2;
            i++;
            j--;
        }

        return ans;
    }
};