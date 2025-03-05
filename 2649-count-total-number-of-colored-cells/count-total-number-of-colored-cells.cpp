class Solution {
 public:
  long long coloredCells(int n) {
    return (long long )(n) * n + (long long)(n - 1) * (n - 1);
  }
};
// class Solution {
// public:
//     long long coloredCells(int n) {
//         long sum =1;
        
//       for(int i=1;i<n;i++)
//       {
//           sum=4*(i) + sum;
//       } 
//      return sum;

//    return {}; }
// };

// class Solution {
// public:
//     long long solve(int n){
//         if(n==1){
//             return 1;
//         }
//         return (n-1)*4 + solve(n-1);
//     }
//     long long coloredCells(int n) {
//         return solve(n);
//     }
// };