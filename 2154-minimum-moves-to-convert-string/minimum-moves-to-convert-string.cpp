class Solution {
 public:
  int minimumMoves(string s) {
    int moves = 0; 
    for (int i = 0; i < s.length(); ) { 
      if (s[i] == 'X') {  
        moves++;  // Ek move lagayenge is 'X' ko cover karne ke liye
        i += 3;   // Agle 2 characters ko bhi skip karenge kyunki ek move 3 chars tak cover karta hai
      } else {
        i++;  // Agar 'O' mila toh bas aage badh jayenge
      }
    }

    return moves; 
  }
};
