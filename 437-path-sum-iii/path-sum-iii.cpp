class Solution {
public:
    int target;

    // Count paths starting exactly from this node
    int count_from_node(TreeNode* node, long long curr_Sum) {
        if (!node) return 0;

        curr_Sum += node->val;

        int count = 0;
        if (curr_Sum == target)
            count++;

        count += count_from_node(node->left, curr_Sum);
        count += count_from_node(node->right, curr_Sum);

        return count;
    }

    int pathSum(TreeNode* root, int target_sum) {
        if (!root) return 0;

        target = target_sum;

        int total_paths = 0;

        // paths which start from this node
        total_paths += count_from_node(root, 0);

        // paths completely in left subtree
        total_paths += pathSum(root->left, target_sum);

        // paths completely in right subtree
        total_paths += pathSum(root->right, target_sum);

        return total_paths;
    }
};
