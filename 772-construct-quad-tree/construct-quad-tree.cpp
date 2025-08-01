/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper_function(vector<vector<int>>& grid, int row, int col, int length) {
        // Step 1: Check if all values are same
        bool all_same = true;
        int first = grid[row][col];

        for (int i = row; i < row + length; ++i) {
            for (int j = col; j < col + length; ++j) {
                if (grid[i][j] != first) {
                    all_same = false;
                    break;
                }
            }
            if (!all_same) break;
        }

        // Step 2: If all values are same, return leaf node
        if (all_same) {
            return new Node(first == 1, true);
        }

        // Step 3: Divide the grid into 4 parts and recurse
        int half = length / 2;
        Node* topLeft = helper_function(grid, row, col, half);
        Node* topRight = helper_function(grid, row, col + half, half);
        Node* bottomLeft = helper_function(grid, row + half, col, half);
        Node* bottomRight = helper_function(grid, row + half, col + half, half);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return helper_function(grid, 0, 0, grid.size());
    }
};
