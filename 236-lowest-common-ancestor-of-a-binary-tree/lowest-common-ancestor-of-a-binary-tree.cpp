class BinaryLifting {
private:
    int LOG;
    unordered_map<int, vector<int>> up;
    unordered_map<int, int> depth;
    unordered_map<int, vector<int>> children;

public:
    BinaryLifting(const unordered_map<int, int>& parent) {
        LOG = 20;  // log2(maxNodes) <= 17 for constraints up to 1e5
        for (auto& p : parent) {
            int node = p.first;
            up[node] = vector<int>(LOG, -1);
        }

        for (auto& [node, par] : parent) {
            up[node][0] = par;
            if (par != -1)
                children[par].push_back(node);
        }

        for (auto& [node, par] : parent) {
            if (par == -1) {
                dfs(node, 0);
            }
        }

        for (int j = 1; j < LOG; ++j) {
            for (auto& [node, _] : parent) {
                int prev = up[node][j - 1];
                if (prev != -1)
                    up[node][j] = up[prev][j - 1];
            }
        }
    }

    void dfs(int node, int d) {
        depth[node] = d;
        for (int child : children[node])
            dfs(child, d + 1);
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                node = up[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = getKthAncestor(u, depth[u] - depth[v]);
        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};
void buildParentMap(TreeNode* root,
                    unordered_map<int, int>& parent,
                    unordered_map<int, TreeNode*>& nodeMap) {
    queue<TreeNode*> q;
    q.push(root);
    parent[root->val] = -1;
    nodeMap[root->val] = root;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr->left) {
            parent[curr->left->val] = curr->val;
            nodeMap[curr->left->val] = curr->left;
            q.push(curr->left);
        }
        if (curr->right) {
            parent[curr->right->val] = curr->val;
            nodeMap[curr->right->val] = curr->right;
            q.push(curr->right);
        }
    }
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, int> parent;
        unordered_map<int, TreeNode*> nodeMap;

        buildParentMap(root, parent, nodeMap);

        BinaryLifting bl(parent);
        int lca_val = bl.getLCA(p->val, q->val);

        return nodeMap[lca_val];
    }
};
