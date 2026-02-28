class Solution {
public:
    bool bfs(vector<int>& arr, int start) {

        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            // found zero
            if (arr[idx] == 0)
                return true;

            int right = idx + arr[idx];
            int left = idx - arr[idx];

            // move right
            if (right < n && !visited[right]) {
                visited[right] = true;
                q.push(right);
            }

            // move left
            if (left >= 0 && !visited[left]) {
                visited[left] = true;
                q.push(left);
            }
        }

        return false;
    }
    bool canReach(vector<int>& arr, int start) { return bfs(arr, start); }
};