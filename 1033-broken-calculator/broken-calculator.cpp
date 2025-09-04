// class Solution {
// public:
//     int brokenCalc(int num, int target) {
//         int size = 2 * target + 1;
//         queue<pair<long long, int>> q; // { current value of num , steps }
//         vector<bool> visited(size, false);
//         q.push({num, 0});

//         visited[num] = true;

//         while (!q.empty()) {
//             auto [curr, steps] = q.front();
//             q.pop();

//             if (curr == target)
//                 return steps;

//             // multiply by 2 ki condition
//             if (curr * 2 < size && !visited[curr * 2]) {
//                 q.push({curr * 2, steps + 1});
//                 visited[curr * 2] = true;
//             }
            
//             // subtract 1 wali condition
//             if (curr - 1 > 0 && !visited[curr - 1]) {
//                 q.push({curr - 1, steps + 1});
//                 visited[curr - 1] = true;
//             }
//         }
//         return -1; // ye kabhi nhi hoga
//     }
// };


class Solution {
public:
    int brokenCalc(int num, int target) {
        int count = 0;
        
        while ( target > num ){
            if(target % 2 == 0) {
                target /= 2 ;
            }
            else {
                target += 1;
            }
            count++;
        }
        return count + (num - target);
    }
};