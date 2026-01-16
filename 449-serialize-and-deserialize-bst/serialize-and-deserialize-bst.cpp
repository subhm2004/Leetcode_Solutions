class Codec {
public:
    // DFS serialize
    string serialize(TreeNode* root) {
        if (!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // DFS deserialize helper
    TreeNode* helper(queue<string>& q) {
        string val = q.front(); q.pop();

        if (val == "null") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = helper(q);
        node->right = helper(q);
        return node;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                q.push(temp);
                temp = "";
            } else temp += c;
        }

        return helper(q);
    }
};
