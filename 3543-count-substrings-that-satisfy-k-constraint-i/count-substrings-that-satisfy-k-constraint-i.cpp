class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int left = 0;
        int zero = 0, one = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            if (s[right] == '0') zero++;
            else one++;

            // invalid window → shrink krte hai 
            while (zero > k && one > k) {
                if (s[left] == '0') zero--;
                else one--;
                left++;
            }

            // valid substrings sari hogi rigth se left ke beech me 
            ans += (right - left + 1);
        }

        return ans;

    }
};