class Solution {
public:
    int n;
    unordered_map<int, list<int>> adjList;
    
    // Step 1: DFS function - har node ka subtree size calculate karega
    // Ye function recursively har node ke niche kitne nodes hain wo count karta hai
    int dfs(int node, int parent, vector<int>& subtree_size) {
        int size = 1; // Current node khud ko count karo (isliye 1 se start)
        
        // Current node ke saare children ko traverse karo
        for (auto &child : adjList[node]) {
            if (child == parent) continue; // Parent ko skip karo (cycle avoid karne ke liye)
            
            // Recursively child ka subtree size nikalo aur current size mein add karo
            size += dfs(child, node, subtree_size);
        }
        
        // Current node ka subtree size store karo
        subtree_size[node] = size;
        return size;
    }
    
    // Step 2: Score calculate karne ka function
    // Jab hum koi node remove karte hain, to kitne subtrees bante hain aur unka score kya hoga
    long long calculate_score(int node, vector<int>& subtree_size) {
        long long score = 1; // Score ko 1 se initialize karo (multiplication ke liye)
        int total = subtree_size[node]; // Current node ke subtree ka total size
        
        // Current node ke har child ka subtree size multiply karo
        for (auto &child : adjList[node]) {
            // Ye condition ensure karti hai ki sirf children consider ho rahe hain
            // (parent nahi, kyunki subtree_size[child] < subtree_size[node] sirf children ke liye true hai)
            if (subtree_size[child] < subtree_size[node]) {
                score *= subtree_size[child]; // Child ke subtree ka size multiply karo
            }
        }
        
        // Baaki nodes jo current node ke subtree ke bahar hain
        // Ye wo nodes hain jo current node ke remove hone ke baad upar ki taraf rah jaenge
        int rest_nodes = n - total;
        if (rest_nodes > 0) {
            score *= rest_nodes; // Upar wale subtree ka size bhi multiply karo
        }
        
        return score;
    }
    
    // Step 3: Main function - sabse important part
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        
        // Adjacency list banao - parent to children mapping
        for (int i = 0; i < n; i++) {
            if (parents[i] != -1) { // Root node (0) ka parent -1 hai, usko skip karo
                adjList[parents[i]].push_back(i); // Parent ke children list mein current node add karo
            }
        }
        
        vector<int> subtree_size(n, 0); // Har node ka subtree size store karne ke liye
        
        // DFS se har node ka subtree size calculate karo (root = 0 se start karo)
        dfs(0, -1, subtree_size);
        
        // Ab har node ka score calculate karke maximum score wale nodes count karo
        long long max_score = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            long long score = calculate_score(i, subtree_size);
            
            if (score > max_score) {
                // Naya maximum score mila
                max_score = score;
                count = 1; // Count reset karo
            } else if (score == max_score) {
                // Same maximum score wala node mila
                count++; // Count badhao
            }
        }
        
        return count; // Kitne nodes mein maximum score hai wo return karo
    }
};

/*
Algorithm Explanation (Hinglish mein):

1. **Tree Construction**: 
   - Parents array se adjacency list banate hain
   - Har parent ke children ko list mein store karte hain

2. **Subtree Size Calculation**:
   - DFS use karke har node ke niche kitne nodes hain wo calculate karte hain
   - Root se start karke recursively har subtree ka size nikaalte hain

3. **Score Calculation**:
   - Har node ko remove karne par kitne subtrees bante hain wo dekhte hain
   - Example: Agar node X ko remove karo to:
     * X ke har child ka subtree alag ho jaega
     * X ke upar wala part (parent side) bhi alag subtree banega
   - Inn sabke sizes ka product hi score hota hai

4. **Maximum Score Count**:
   - Saare nodes ka score calculate karke maximum find karte hain
   - Kitne nodes mein ye maximum score hai wo count karte hain

Time Complexity: O(n) - har node ko ek baar visit karte hain
Space Complexity: O(n) - adjacency list aur arrays ke liye

Example:
Tree: 0-1-2-3 (linear tree)
parents = [-1, 0, 1, 2]

Node 0 remove: subtrees = [1,2,3] → score = 3
Node 1 remove: subtrees = [0], [2,3] → score = 1 * 2 = 2  
Node 2 remove: subtrees = [0,1], [3] → score = 2 * 1 = 2
Node 3 remove: subtrees = [0,1,2] → score = 3

Maximum score = 3, count = 1 (only node 0)
*/