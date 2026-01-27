class BinaryLifting {
private:
    int n;
    int LOG;
    vector<vector<int>> up;

public:
    BinaryLifting(int n, const vector<int>& parent) {
        this->n = n;
        LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1));

        // Set 2^0-th parent
        for (int i = 0; i < n; ++i) {
            up[i][0] = parent[i];
        }

        // Precompute 2^j-th ancestors
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                if (up[i][j - 1] != -1)
                    up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
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
};

class TreeAncestor {
private:
    BinaryLifting* bl;

public:
    TreeAncestor(int n, vector<int>& parent) {
        bl = new BinaryLifting(n, parent);
    }

    int getKthAncestor(int node, int k) {
        return bl->getKthAncestor(node, k);
    }

    ~TreeAncestor() {
        delete bl;  
    }
};
