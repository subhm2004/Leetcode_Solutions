class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        queue<int> q;

        // Step 1: start digits 1–9 (no leading zero)
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }

        int length = 1; // current length of numbers

        while (!q.empty()) {
            int size = q.size();

            // If numbers have reached length n, push to ans
            if (length == n) {
                while (!q.empty()) {
                    ans.push_back(q.front());
                    q.pop();
                }
                break;
            }

            // Step 2: Expand all numbers in this length
            for (int i = 0; i < size; ++i) {
                int num = q.front(); q.pop();
                int lastDigit = num % 10;

                // Next possible digits
                if (lastDigit + k <= 9)
                    q.push(num * 10 + (lastDigit + k));
                if (k > 0 && lastDigit - k >= 0)
                    q.push(num * 10 + (lastDigit - k));
            }

            length++; // increase number length
        }

        return ans;
    }
};
