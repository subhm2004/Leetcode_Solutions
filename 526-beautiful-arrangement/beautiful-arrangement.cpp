class Solution {
public:
    int count = 0;

    void backtrack(int n, int i, vector<bool>& visited) {
        if (i > n) {
            count++;
            return;
        }

        for (int num = 1; num <= n; num++) {
            if (!visited[num] && (num % i == 0 || i % num == 0)) {
                visited[num] = true;
                backtrack(n, i + 1, visited);
                visited[num] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        backtrack(n, 1, visited);
        return count;
    }
};
