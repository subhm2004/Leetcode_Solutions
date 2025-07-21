class TrieNode {
public:
    vector<string> suggestions;
    TrieNode* children[26] = {};

    void insert_suggestion(string& word) {
        if (suggestions.size() < 3)
            suggestions.push_back(word);   
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
            node->insert_suggestion(word);  
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());  
        for (string& word : products)
            insert(word);   

        vector<vector<string>> ans;
        TrieNode* node = root;
        for (char c : searchWord) {
            if (node)
                node = node->children[c - 'a'];
            if (node)
                ans.push_back(node->suggestions);
            else
                ans.push_back({});  
        }
        return ans;
    }
};
