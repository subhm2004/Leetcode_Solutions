class UnionFind
{
public:
    vector<int> parent;
    vector<int> rank;

    // Constructor
    // Har node ko initially uska khud ka parent bana dete hain.
    // Matlab shuru me har node ek alag connected component hai.
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Root (Representative) find karne ka function.
    // Path Compression use kar rahe hain taaki future find() fast ho jaye.
    int find(int x)
    {
        // Agar khud hi root hai to wahi return kar do.
        if (parent[x] == x)
            return x;

        // Root find karke direct parent bana do.
        return parent[x] = find(parent[x]);
    }

    // Do components ko merge karne ka function.
    // Union By Rank use kar rahe hain.
    void UNION_BY_RANK(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);

        // Agar dono already same component me hain
        // to kuch karne ki zarurat nahi.
        if (parentX == parentY)
            return;

        // Chhoti height wale tree ko badi height wale tree ke niche jod do.
        if (rank[parentX] < rank[parentY])
        {
            parent[parentX] = parentY;
        }
        else if (rank[parentX] > rank[parentY])
        {
            parent[parentY] = parentX;
        }
        else
        {
            // Agar dono ki height same hai
            // to kisi ek ko parent bana do
            // aur uski rank badha do.
            parent[parentX] = parentY;
            rank[parentY]++;
        }
    }
};

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        // -------------------------------------------------------
        // STEP 1 : DSU Object banao
        // -------------------------------------------------------
        UnionFind uf(n);

        // -------------------------------------------------------
        // STEP 2 : Saari edges ko union karo.
        // Iske baad same connected component ke
        // saare nodes ka root same ho jayega.
        // -------------------------------------------------------
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            uf.UNION_BY_RANK(u, v);
        }

        // node_count[root] = us component me kitne nodes hain.
        unordered_map<int, int> node_count;

        // edge_count[root] = us component me kitni edges hain.
        unordered_map<int, int> edge_count;

        // -------------------------------------------------------
        // STEP 3 : Har node ka root find karo.
        // Fir us root ke against node count badha do.
        // -------------------------------------------------------
        for (int i = 0; i < n; i++)
        {
            int root = uf.find(i);

            node_count[root]++;
        }

        // -------------------------------------------------------
        // STEP 4 : Har edge kis component ki hai?
        //
        // Kyunki union already ho chuka hai,
        // edge ke dono endpoints ka root same hoga.
        //
        // Isliye edge_count[root]++ kar denge.
        // -------------------------------------------------------
        for (auto &edge : edges)
        {
            int u = edge[0];

            int root = uf.find(u);

            edge_count[root]++;
        }

        int complete_components = 0;

        // -------------------------------------------------------
        // STEP 5 : Har connected component ko check karo.
        // -------------------------------------------------------
        for (auto &component : node_count)
        {
            int root = component.first;

            // Component me total nodes
            int nodes = component.second;

            // Complete graph me required edges hoti hain:
            //
            // n*(n-1)/2
            //
            // Example:
            //
            // 3 nodes -> 3 edges
            // 4 nodes -> 6 edges
            // 5 nodes -> 10 edges
            //
            int required_edges = nodes * (nodes - 1) / 2;

            // Is component me actual kitni edges hain.
            int actual_edges = edge_count[root];

            // Agar required aur actual same hain
            // to ye component complete hai.
            if (required_edges == actual_edges)
                complete_components++;
        }

        return complete_components;
    }
};