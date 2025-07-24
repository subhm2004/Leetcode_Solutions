class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = k;
        int i = num.size() - 1;

        while (i >= 0 || carry > 0) {
            int digit = (i >= 0) ? num[i] : 0;
            int sum = digit + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
            i--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
