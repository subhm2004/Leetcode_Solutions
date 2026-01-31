class Solution {
public:
    int countSymmetricIntegers(int low, int high) {

        int ans = 0;

        for(int x = low; x <= high; x++) {

            string s = to_string(x);
            int len = s.size();

            if(len & 1) continue;

            int n = len / 2;
            int a = 0, b = 0;

            for(int i = 0; i < n; i++) a += s[i] - '0';
            for(int i = n; i < len; i++) b += s[i] - '0';

            if(a == b) ans++;
        }

        return ans;
    }
};
