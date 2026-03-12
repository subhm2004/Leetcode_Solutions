class Solution {
public:
    int bfs(vector<int>& nums, int start, int goal) {

        int n = nums.size();

        vector<bool> visited(1001, 0);
        queue<int> q; // BFS

        q.push(start);
        int ans = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int curr = q.front();
                q.pop();

                if (curr == goal)
                    return ans;

                if (curr < 0 || curr > 1000 || visited[curr] == 1)
                    continue;

                visited[curr] = 1;

                for (int i = 0; i < n; i++) {

                    int a = curr + nums[i];
                    int b = curr - nums[i];
                    int c = curr ^ nums[i];

                    q.push(a);
                    q.push(b);
                    q.push(c);
                }
            }

            ans++;
        }

        return -1;
    }
    int minimumOperations(vector<int>& nums, int start, int goal) {
        return bfs(nums, start, goal);
    }
};
