class Solution {
public:
    vector<TreeNode*> generateFBT(int n) {
        if (n == 1) return {new TreeNode(0)};
        
        vector<TreeNode*> result;
        for (int leftSize = 1; leftSize < n; leftSize += 2) {
            int rightSize = n - 1 - leftSize;
            vector<TreeNode*> leftSubtrees = generateFBT(leftSize);
            vector<TreeNode*> rightSubtrees = generateFBT(rightSize);
            
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    result.push_back(new TreeNode(0, left, right));
                }
            }
        }
        return result;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return (n % 2 == 0) ? vector<TreeNode*>() : generateFBT(n);
    }
};
