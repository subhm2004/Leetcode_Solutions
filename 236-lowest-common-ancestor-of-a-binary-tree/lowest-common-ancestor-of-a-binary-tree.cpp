class Binary_lifting {
private:
    int LOG;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, TreeNode*> node_Map;
    unordered_map<int, vector<int>> up;
    unordered_map<int, int> depth;
    unordered_map<int, int> parent_Of;
    int n;
    const int NO_PARENT = INT_MIN;  

public:
    void build_Graph(TreeNode* root) {
        if (!root)
            return;
        node_Map[root->val] = root;
        if (root->left) {
            adjList[root->val].push_back(root->left->val);
            adjList[root->left->val].push_back(root->val);
            build_Graph(root->left);
        }
        if (root->right) {
            adjList[root->val].push_back(root->right->val);
            adjList[root->right->val].push_back(root->val);
            build_Graph(root->right);
        }
    }

    void dfs(int curr_node, int parent) {
        parent_Of[curr_node] = parent;
        
        if (parent == NO_PARENT)
            depth[curr_node] = 0;
        else
            depth[curr_node] = depth[parent] + 1;

        for (int nbr : adjList[curr_node]) {
            if (nbr == parent)
                continue;
            dfs(nbr, curr_node);
        }
    }

    void build(TreeNode* root) {
        build_Graph(root);
        n = node_Map.size();
        LOG = ceil(log2(n)) + 1;

        dfs(root->val, NO_PARENT);

        // Initialize up table for all nodes FIRST
        for (auto& x : node_Map) {
            up[x.first].assign(LOG, NO_PARENT);
        }

        // Then set up[v][0] = parent
        for (auto& x : node_Map) {
            up[x.first][0] = parent_Of[x.first];
        }

        // Fill binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (auto& x : node_Map) {
                int node = x.first;
                int prev_Ancestor = up[node][j - 1];
                
                // Check if prev_Ancestor exists and is valid
                if (prev_Ancestor != NO_PARENT && up.count(prev_Ancestor)) {
                    up[node][j] = up[prev_Ancestor][j - 1];
                }
            }
        }
    }

    int jump(int node, int k) {
        for (int i = 0; i < LOG && node != NO_PARENT; i++) {
            if (k & (1 << i)) {
                node = up[node][i];
            }
        }
        return node;
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v])
            v = jump(v, depth[v] - depth[u]);
        else if (depth[u] > depth[v])
            u = jump(u, depth[u] - depth[v]);

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != NO_PARENT && up[v][i] != NO_PARENT && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    TreeNode* get_Node(int val) { 
        if (node_Map.count(val)) {
            return node_Map[val];
        }
        return nullptr;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Binary_lifting bl;
        bl.build(root);
        int lcaVal = bl.LCA(p->val, q->val);
        return bl.get_Node(lcaVal);
    }
};