class Solution {
public:
    long long calculateScore(vector<string>& instructions,
                             vector<int>& values) {
        int n = instructions.size();
        long long score = 0;
        int i = 0;
        vector<bool> visited(n, false);

        while (i >= 0 && i < n && !visited[i]) {
            visited[i] = true;

            if (instructions[i] == "add") {
                score += values[i];
                i++;
            } else {
                i = i + values[i];
            }
        }
        return score;
    }
};
