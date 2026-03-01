class Solution {
public:
    int solve_BFS(vector<int>& arr, int& n) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> mp; // value-> kis kis index pr hai present wo value
        //why ?  Because, we need to access those indices where arr[i] == arr[j]
        
        for(int i = 0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            //check this level
            while(size--) {
                int curr = q.front();
                q.pop();
                
                if(curr == n-1) {
                    //BFS ensures minimum steps
                    //We are moving level by level
                    return steps;
                }
                
                int left  = curr-1;
                int right = curr+1;
                
                if(left >= 0 && !visited[left]) {
                    q.push(left);
                    visited[left] = true;
                }
                
                if(right < n && !visited[right]) {
                    q.push(right);
                    visited[right] = true;
                }
                
                for(const int &idx : mp[arr[curr]]) {
                    if(!visited[idx]) {
                        q.push(idx);
                        visited[idx] = true;
                    }
                }
                //If you don't erase it, you may be again checking for it
                //in future. It will cause TLE
                mp.erase(arr[curr]);
            }
            steps++;
        }
        
        return -1;
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        return solve_BFS(arr, n);
    }
};
