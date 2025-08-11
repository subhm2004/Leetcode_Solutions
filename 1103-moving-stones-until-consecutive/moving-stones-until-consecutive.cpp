class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> position = {a, b, c};
        sort(position.begin(), position.end());
        int x = position[0], y = position[1], z = position[2];
        
        int left_gap  = y - x;
        int right_gap = z - y;
        
        // Max moves
        int max_moves = (left_gap - 1) + (right_gap - 1);
        
        // Min moves
        int min_moves = INT_MAX;
        if (left_gap == 1 && right_gap == 1) 
            min_moves = 0;
        else if (left_gap <= 2 || right_gap <= 2) 
            min_moves = 1;
        else 
            min_moves = 2;
        
        return {min_moves, max_moves};
    }
};
