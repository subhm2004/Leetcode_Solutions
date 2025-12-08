class Solution {
public:
    int countTriples(int n) {
        vector<int> squares(n + 1);
        for (int i = 1; i <= n; ++i) {
            squares[i] = i * i;
        }

        int ans = 0;

        for (int c = 1; c <= n; ++c) {
            int target = squares[c];
            int left = 1, right = c - 1;

            while (left <= right) {
                int sum = squares[left] + squares[right];

                if (sum == target) {
                    ans += (left == right ? 1 : 2);
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return ans;
    }
};
