class Solution {
public:
    int n;
    unordered_map<int, list<int>> adjList;

    // Step 1: DFS function -> har node ka subtree size calculate karega
    int dfs(int node, int parent, vector<int>& subtree_size) {
        int size = 1; // apna size 1
        for (auto &child : adjList[node]) {
            if (child == parent) continue; // back edge avoid
            size += dfs(child, node, subtree_size); 
        }
        subtree_size[node] = size;
        return size;
    }

    // Step 2: Score calculate karne ka function
    long long calculate_score(int node, vector<int>& subtree_size) {
        long long score = 1;
        int total = subtree_size[node]; // current node ke subtree ka size

        // Har child ke subtree ka size multiply karo
        for (auto &child : adjList[node]) {
            if (subtree_size[child] < subtree_size[node]) { 
                score *= subtree_size[child];
            }
        }

        // baaki nodes jo is node ke subtree ke bahar bache
        int rest_nodes = n - total;
        if (rest_nodes > 0) score *= rest_nodes;

        return score;
    }

    // Step 3: Main function
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();

        // Adjacency list banao
        for (int i = 0; i < n; i++) {
            if (parents[i] != -1) {
                adjList[parents[i]].push_back(i);
            }
        }

        vector<int> subtree_size(n, 0);

        // DFS se har node ka subtree size nikalo
        dfs(0, -1, subtree_size);

        // Ab har node ka score nikalke max count karo
        long long max_score = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            long long score = calculate_score(i, subtree_size);

            if (score > max_score) {
                max_score = score;
                count = 1;
            } else if (score == max_score) {
                count++;
            }
        }

        return count;
    }
};
