// class Solution {
// public:
//     bool is_valid(int nx, int ny, int targetX, int targetY, vector<pair<int,int>>& visited) {
//         if (nx <= 0 || ny <= 0) return false;                    
//         if (nx > targetX * 2 || ny > targetY * 2) return false;  

//         for (auto &p : visited) {
//             if (p.first == nx && p.second == ny) return false;
//         }
//         return true;
//     }

//     bool bfs(int targetX, int targetY) {
//         queue<pair<int,int>> q;
//         vector<pair<int,int>> visited;

//         q.push({1,1});
//         visited.push_back({1,1});

//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();

//             if (x == targetX && y == targetY) return true;

//             vector<pair<int,int>> next_moves = {
//                 {x, y - x},
//                 {x - y, y},
//                 {2 * x, y},
//                 {x, 2 * y}
//             };

//             for (auto [nx, ny] : next_moves) {
//                 if (is_valid(nx, ny, targetX, targetY, visited)) {
//                     visited.push_back({nx, ny});
//                     q.push({nx, ny});
//                 }
//             }
//         }
//         return false;
//     }

//     bool isReachable(int targetX, int targetY) {
//         return bfs(targetX, targetY);
//     }
// };


class Solution {
public:
    bool isReachable(long long targetX, long long targetY) {
        long long g = gcd(targetX, targetY);
        // check if gcd is power of 
        
        // return __builtin_popcountll(g) == 1 ;
        return (g & (g - 1)) == 0;
    }
};




// Return true iff (targetX, targetY) is reachable from (1,1).
    //
    // Reasoning summary (also explained inline below):
    //  - Forward moves:
    //      (x, y) -> (x, y - x)    // subtract x from y
    //      (x, y) -> (x - y, y)    // subtract y from x
    //      (x, y) -> (2x, y)       // double x
    //      (x, y) -> (x, 2y)       // double y
    //
    //  - Subtraction moves act exactly like repeated steps of the Euclidean GCD algorithm;
    //    they **preserve gcd(x,y)** (removing common factors does not introduce new primes).
    //  - Doubling moves only multiply one coordinate by 2, so they can only introduce the prime 2
    //    into the gcd. No other prime factor can ever be introduced by the allowed moves.
    //
    // => Therefore the gcd of (targetX, targetY) must be a power of two (2^k) for the point to be reachable
    //    from (1,1). The code below computes gcd and checks that condition.



     // Compute gcd(a,b) using the Euclidean algorithm.
        // We use the form:
        //    while (b != 0) {
        //        if (a > b) a = a % b;
        //        else b = b % a;
        //    }
        //
        // This is essentially the fast version of:
        //    while (a != b) {
        //        if (a > b) a = a - b;   // repeated subtraction if a > b
        //        else b = b - a;         // repeated subtraction if b > a
        //    }
        //
        // Explanation of "if a > b" / "if b > a" behavior:
        //  - When a > b: doing `a = a % b` is equivalent to repeatedly applying the forward move
        //    (x - y, y) many times (i.e., a -= b repeated) until a < b. This simulates repeated subtraction.
        //  - When b > a: doing `b = b % a` is equivalent to repeatedly applying the forward move
        //    (x, y - x) many times (i.e., b -= a repeated) until b < a.
        //  - Those subtraction-type moves preserve gcd, so this loop finds the gcd quickly.

