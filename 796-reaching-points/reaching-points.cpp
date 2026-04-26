


// class Solution {
// public:
//     bool reachingPoints(int sx, int sy, int tx, int ty) {
//         // gcd pruning: agar gcd mismatch hai to impossible
//         if (gcd(sx, sy) != gcd(tx, ty)) return false;

//         // base cases
//         if (tx < sx || ty < sy) return false;
//         if (tx == sx && ty == sy) return true;

//         if (tx > ty) {
//             return reachingPoints(sx, sy, tx - ty, ty);
//         } else {
//             return reachingPoints(sx, sy, tx, ty - tx);
//         }
//     }
// };


class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // gcd pruning
        if ( __gcd(sx, sy) !=  __gcd(tx, ty)) return false;

        // base cases
        if (tx < sx || ty < sy) return false;
        if (tx == sx && ty == sy) return true;

       if (tx > ty) {
            if (sy == ty) return (tx - sx) % ty == 0;
            return reachingPoints(sx, sy, tx % ty, ty);   
        } else {
            if (sx == tx) return (ty - sy) % tx == 0;
            return reachingPoints(sx, sy, tx, ty % tx);  
        }
    }
};
