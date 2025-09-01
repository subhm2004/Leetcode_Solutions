class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for (char& move : moves) {
      if (move == 'R') x++;
      if (move == 'L') x--;
      if (move == 'U') y++;
      if (move == 'D') y--;
    }

    return x == 0 && y == 0;
  }
};