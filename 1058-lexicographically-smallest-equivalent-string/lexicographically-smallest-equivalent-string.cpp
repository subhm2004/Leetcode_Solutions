// Disjoint Set Union (Union-Find) class
class UnionFind {
public:
    vector<int> parent; // Har node ka parent track karne ke liye
    vector<int> rank;   // Rank ka istemal tree height optimize karne ke liye (yaha ignore ho raha hai)

    // Constructor - har element initially apna khud ka parent hota hai
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Recursively root dhoondo aur path compression lagao
    }

    // Union function - hamesha chhoti lexicographic value ko parent banao
    void unionByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        // Agar dono same component me hain to kuch mat karo
        if (x_parent == y_parent)
            return;

        // Lexicographically chhoti value ko parent banao
        if (x_parent < y_parent) {
            parent[y_parent] = x_parent;
        } else {
            parent[x_parent] = y_parent;
        }
    }
};

// Solution class
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26); // 26 lowercase letters ke liye Union-Find banao

        // s1 aur s2 ke har pair ke characters ko equivalent banao
        for (int i = 0; i < s1.size(); ++i) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            uf.unionByRank(a, b); // Unka relation Union-Find me jodo
        }

        // baseStr ke har character ke liye uska smallest equivalent character dhoondo
        string ans;
        for (char c : baseStr) {
            int smallestChar = uf.find(c - 'a'); // Is character ka representative dhoondo
            ans += (char)(smallestChar + 'a');   // Representative ko string me jodo
        }

        return ans; // Final smallest equivalent string return karo
    }
};
