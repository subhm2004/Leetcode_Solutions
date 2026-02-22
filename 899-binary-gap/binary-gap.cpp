class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();

        int last = -1;
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            if (s[i] == '1') {
                if (last != -1)
                    ans = max(ans, i - last);
                last = i;
            }
        }

        return ans;
    }
};