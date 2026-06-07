class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes; // Har node ko store karne ke liye map
        unordered_map<int, int> parentCount; // Har node ke liye parent count store karega

        // Sare nodes create karna aur unke relationships set karna
        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];

            // Agar parent ya child node pehle se exist nahi karti, to naye nodes banao
            if (!nodes[parent]) nodes[parent] = new TreeNode(parent);
            if (!nodes[child]) nodes[child] = new TreeNode(child);

            // Parent-child relationship set karna
            if (isLeft) 
                nodes[parent]->left = nodes[child]; // Agar isLeft == 1 hai to left child banao
            else 
                nodes[parent]->right = nodes[child]; // Warna right child banao

            // Child ka parent count badhao, kyunki yeh kisi ka child ban gaya hai
            parentCount[child]++;
        }

        // Root wahi node hogi jo kisi aur ki child nahi hai
        for (auto& d : descriptions) {
            if (parentCount.find(d[0]) == parentCount.end()) { // Jo kisi aur ka child nahi hai wahi root hai
                return nodes[d[0]];
            }
        }
        return nullptr; // Yeh case tabhi hoga jab input galat ho
    }
};
