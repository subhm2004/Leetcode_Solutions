class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int blanks = 0;

        for (int i = 0; i < moves.size(); i++) {

            if (moves[i] == 'U')
                y++;

            else if (moves[i] == 'D')
                y--;

            else if (moves[i] == 'R')
                x++;

            else if (moves[i] == 'L')
                x--;

            else
                blanks++;
        }

        return abs(x) + abs(y) + blanks;
    }
};