class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0); // Initialize answer array with 0

        if (k == 0) 
            return ans;

        int step = (k > 0) ? 1 : -1; // Determine direction
        int steps = abs(k); // Get absolute number of steps

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            int index = i;

            for (int j = 0; j < steps; ++j) {
                index = (index + step + n) % n; // Move in the circular array
                sum += code[index];
            }

            ans[i] = sum;
        }

        return ans;
    }
};
