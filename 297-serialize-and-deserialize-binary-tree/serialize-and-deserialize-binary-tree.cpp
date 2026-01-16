// DFS based serialize and deserialize (Pre Order)
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
/* Level Order serialize and deserialize


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

*/