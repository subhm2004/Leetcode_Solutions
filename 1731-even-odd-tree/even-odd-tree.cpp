class Solution {
public:
    bool dfs(TreeNode* root, int level, vector<int>& prevValues) {
        if (!root) return true; // Agar node null ho toh true return karo

        // Even level -> Odd values & Increasing
        // Odd level -> Even values & Decreasing
        if ((level % 2 == 0 && (root->val % 2 == 0)) ||  
            (level % 2 == 1 && (root->val % 2 == 1)))  
            return false; 

        if (level >= prevValues.size())  
            prevValues.push_back(root->val); // Pehli baar visit ho raha hai level
        else {
            int& prevVal = prevValues[level]; // Level ki last value ka reference
            if ((level % 2 == 0 && root->val <= prevVal) || 
                (level % 2 == 1 && root->val >= prevVal))  
                return false; // Increasing/Decreasing condition check

            prevVal = root->val; // Last value update karo
        }

        return dfs(root->left, level + 1, prevValues) && 
               dfs(root->right, level + 1, prevValues);
    }

    bool isEvenOddTree(TreeNode* root) {
        vector<int> prevValues; // Level wise last dekha gaya value store karega
        return dfs(root, 0, prevValues);
    }
};
