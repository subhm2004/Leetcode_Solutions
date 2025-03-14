class Solution {
public:
    string winningPlayer(int x, int y) {
        int moves = min(x, y / 4); // Maximum valid moves possible
        return (moves % 2 == 0) ? "Bob" : "Alice";
    }
};
