class UnionFind {
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;  
        }
    }

    // Path compression 
    int find(int x) {
        if(parent[x] == x) {
            return x;   
        }
        return parent[x] = find(parent[x]);
    }


    void UNION_BY_RANK(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) {
            return;  
        }

        if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        }
        else if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        }
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n,
                                vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {
        UnionFind uf(n);
        vector<bool> ans;

        for(auto &request : requests) {
            int u = request[0];
            int v = request[1];

            // u aur v ke group representatives dhundh te hai
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);

            bool possible = true;

            // Har restriction check krte hai 
            // Agar u aur v ko merge karein toh koi restriction toot ti hai kya?
            for(auto &restriction : restrictions) {
                int x = restriction[0];
                int y = restriction[1];

                // x aur y ke current group representatives
                int parent_x = uf.find(x);
                int parent_y = uf.find(y);

                // Case 1: parent_x == parent_u && parent_y == parent_v
                //   matlab u wale group mein x hai
                //         v wale group mein y hai
                //   merge karne se x aur y ek group mein aa jayenge → VIOLATION
                

                // Case 2: parent_x == parent_v && parent_y == parent_u
                //   ulta — v wale group mein x hai
                //          u wale group mein y hai
                //   ye bhi same violation hai
                if((parent_x == parent_u && parent_y == parent_v) ||
                   (parent_x == parent_v && parent_y == parent_u))
                {
                    possible = false;  // ye friendship nahi ho sakti
                    break;
                }
            }

            if(possible) {
                // Koi restriction violate nahi hui to  Dono ko ek group mein merge karo
                uf.UNION_BY_RANK(u, v);
                ans.push_back(true);
            }
            else {
                // Restriction violate hoti — merge mat karo and Groups waise hi rehte hain
                ans.push_back(false);
            }
        }

        return ans;
    }
};