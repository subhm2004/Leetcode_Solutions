class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string serialized_str = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                serialized_str += "null ";
                continue;
            }

            serialized_str += to_string(node->val) + " ";
            q.push(node->left);
            q.push(node->right);
        }

        return serialized_str;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        vector<string> nodes;
        string temp = "";

        // string ko tokens me todna
        for (char c : data) {
            if (c == ' ') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        if (nodes[0] == "null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // left child
            if (nodes[i] != "null") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            // right child
            if (i < nodes.size() && nodes[i] != "null") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};
