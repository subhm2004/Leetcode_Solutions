class Solution {
public:
    int total_pieces;
    vector<string> piece_type;
    vector<pair<int,int>> piece_position;
    int ans = 0;

    // Directions
    vector<pair<int,int>> rook_dir   = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<pair<int,int>> bishop_dir = {{1,1},{1,-1},{-1,1},{-1,-1}};
    vector<pair<int,int>> queen_dir  = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

    bool is_inside_board(int r, int c) {
        return r >= 1 && r <= 8 && c >= 1 && c <= 8;
    }

    // Generate all possible destinations for a piece
    vector<vector<pair<int,int>>> generate_paths(int piece_idx) {
        vector<vector<pair<int,int>>> paths;
        vector<pair<int,int>> directions;

        if(piece_type[piece_idx] == "rook") directions = rook_dir;
        else if(piece_type[piece_idx] == "bishop") directions = bishop_dir;
        else directions = queen_dir;

        // Stay in place
        paths.push_back({piece_position[piece_idx]});

        // Explore all directions
        for(auto dir: directions){
            int r = piece_position[piece_idx].first;
            int c = piece_position[piece_idx].second;
            vector<pair<int,int>> path;

            while(true){
                r += dir.first;
                c += dir.second;
                if(!is_inside_board(r,c)) break;
                path.push_back({r,c});
                paths.push_back(path); // path ending here
            }
        }
        return paths;
    }

    // Check if chosen paths have collision at same second
    bool is_valid_paths(const vector<vector<pair<int,int>>>& chosen_paths) {
        int max_len = 0;
        for(auto &p: chosen_paths) max_len = max(max_len, (int)p.size());

        for(int t = 0; t < max_len; t++){
            set<pair<int,int>> seen;
            for(int i = 0; i < chosen_paths.size(); i++){
                pair<int,int> pos;
                if(t < chosen_paths[i].size()) pos = chosen_paths[i][t]; // moving
                else pos = chosen_paths[i].back(); // reached destination

                if(seen.count(pos)) return false;
                seen.insert(pos);
            }
        }
        return true;
    }

    // DFS to try all move combinations
    void dfs(int idx, vector<vector<vector<pair<int,int>>>> &all_piece_paths, vector<vector<pair<int,int>>>& chosen_paths) {
        if(idx == total_pieces){
            if(is_valid_paths(chosen_paths)) ans++;
            return;
        }

        for(auto &path: all_piece_paths[idx]){
            chosen_paths.push_back(path);
            dfs(idx+1, all_piece_paths, chosen_paths);
            chosen_paths.pop_back();
        }
    }

    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions){
        piece_type = pieces;
        total_pieces = pieces.size();
        piece_position.clear();
        for(auto &pos: positions) piece_position.push_back({pos[0], pos[1]});

        // Generate all paths for all pieces
        vector<vector<vector<pair<int,int>>>> all_piece_paths(total_pieces);
        for(int i = 0; i < total_pieces; i++){
            all_piece_paths[i] = generate_paths(i);
        }

        ans = 0;
        vector<vector<pair<int,int>>> chosen_paths;
        dfs(0, all_piece_paths, chosen_paths);
        return ans;
    }
};
