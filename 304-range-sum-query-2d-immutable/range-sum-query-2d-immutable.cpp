class SegmentTree2D {
private:
    int m, n;
    vector<vector<int>> segTree;
    vector<vector<int>> mat;

    void buildY(int nodeX, int lx, int rx, int nodeY, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                segTree[nodeX][nodeY] = mat[lx][ly];
            else
                segTree[nodeX][nodeY] = segTree[2 * nodeX + 1][nodeY] + segTree[2 * nodeX + 2][nodeY];
        } else {
            int my = (ly + ry) / 2;
            buildY(nodeX, lx, rx, 2 * nodeY + 1, ly, my);
            buildY(nodeX, lx, rx, 2 * nodeY + 2, my + 1, ry);
            segTree[nodeX][nodeY] = segTree[nodeX][2 * nodeY + 1] + segTree[nodeX][2 * nodeY + 2];
        }
    }

    void buildX(int nodeX, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            buildX(2 * nodeX + 1, lx, mx);
            buildX(2 * nodeX + 2, mx + 1, rx);
        }
        buildY(nodeX, lx, rx, 0, 0, n - 1);
    }

    void updateY(int nodeX, int lx, int rx, int nodeY, int ly, int ry, int x, int y, int val) {
        if (ly == ry) {
            if (lx == rx)
                segTree[nodeX][nodeY] = val;
            else
                segTree[nodeX][nodeY] = segTree[2 * nodeX + 1][nodeY] + segTree[2 * nodeX + 2][nodeY];
        } else {
            int my = (ly + ry) / 2;
            if (y <= my)
                updateY(nodeX, lx, rx, 2 * nodeY + 1, ly, my, x, y, val);
            else
                updateY(nodeX, lx, rx, 2 * nodeY + 2, my + 1, ry, x, y, val);
            segTree[nodeX][nodeY] = segTree[nodeX][2 * nodeY + 1] + segTree[nodeX][2 * nodeY + 2];
        }
    }

    void updateX(int nodeX, int lx, int rx, int x, int y, int val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx)
                updateX(2 * nodeX + 1, lx, mx, x, y, val);
            else
                updateX(2 * nodeX + 2, mx + 1, rx, x, y, val);
        }
        updateY(nodeX, lx, rx, 0, 0, n - 1, x, y, val);
    }

    int queryY(int nodeX, int nodeY, int ly, int ry, int qly, int qry) {
        if (qry < ly || ry < qly) return 0;
        if (qly <= ly && ry <= qry) return segTree[nodeX][nodeY];
        int my = (ly + ry) / 2;
        return queryY(nodeX, 2 * nodeY + 1, ly, my, qly, qry) +
               queryY(nodeX, 2 * nodeY + 2, my + 1, ry, qly, qry);
    }

    int queryX(int nodeX, int lx, int rx, int qlx, int qrx, int qly, int qry) {
        if (qrx < lx || rx < qlx) return 0;
        if (qlx <= lx && rx <= qrx) return queryY(nodeX, 0, 0, n - 1, qly, qry);
        int mx = (lx + rx) / 2;
        return queryX(2 * nodeX + 1, lx, mx, qlx, qrx, qly, qry) +
               queryX(2 * nodeX + 2, mx + 1, rx, qlx, qrx, qly, qry);
    }

public:
    SegmentTree2D(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        mat = matrix;
        segTree.assign(4 * m, vector<int>(4 * n, 0));
        buildX(0, 0, m - 1);
    }

    int query(int row1, int col1, int row2, int col2) {
        return queryX(0, 0, m - 1, row1, row2, col1, col2);
    }

    void update(int row, int col, int val) {
        mat[row][col] = val;
        updateX(0, 0, m - 1, row, col, val);
    }
};

class NumMatrix {
private:
    SegmentTree2D* segTree;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        segTree = new SegmentTree2D(matrix);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return segTree->query(row1, col1, row2, col2);
    }

    // void update(int row, int col, int val) { // Mutable
    //     segTree->update(row, col, val);
    // }
};
