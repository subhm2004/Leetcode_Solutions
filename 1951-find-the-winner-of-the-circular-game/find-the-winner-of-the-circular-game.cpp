// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         vector<int> arr;
//         for(int i = 1; i <= n; i++) {
//             arr.push_back(i);
//         }

//         int i = 0; //Game starts from 1st player which is sitting at index 0 in arr

//         while(arr.size() > 1) {
//             int idx = (i + k - 1) % arr.size();

//             arr.erase(arr.begin() + idx);

//             i = idx;
//         }

//         return arr[0];
//     }
// };



class Solution { //Josephus Problem
public:
    int solveRE(int n, int k) { // ye 0 index based solve kr diya hai 
        if (n == 1)
            return 0;
        return (solveRE(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) { return solveRE(n, k) + 1; } // 1 baed idx me convert kr diya
};
