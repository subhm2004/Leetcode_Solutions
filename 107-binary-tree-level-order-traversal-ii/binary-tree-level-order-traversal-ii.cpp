class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {}; // Agar tree empty hai toh return karo

    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root); // Root ko queue me daal do

    while (!q.empty()) {
      int sz = q.size(); // Current level ke nodes count karo
      vector<int> level; // Current level ke values store karne ke liye

      while (sz--) { // Jab tak current level ke sabhi nodes process na ho jaaye
        TreeNode* node = q.front();
        q.pop();
        level.push_back(node->val);

        if (node->left) q.push(node->left);  // Left child ko queue me daal do
        if (node->right) q.push(node->right); // Right child ko queue me daal do
      }

      ans.push_back(level); // Current level ko answer me add karo
    }
    reverse(ans.begin(),ans.end());
    return ans;
  }
};