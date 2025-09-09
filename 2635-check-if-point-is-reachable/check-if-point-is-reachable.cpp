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
        
        return __builtin_popcountll(g) == 1 ;
        // return (g & (g - 1)) == 0;
    }
};
