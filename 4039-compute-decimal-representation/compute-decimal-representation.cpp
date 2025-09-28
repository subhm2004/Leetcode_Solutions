class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long place_value = 1;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                ans.push_back(digit * place_value);
            }
            place_value *= 10;
            n /= 10;
        }
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};