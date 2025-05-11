class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    for (int i = 0; i + 2 < arr.size(); ++i) {
      if ((arr[i] % 2 == 1) && (arr[i + 1] % 2 == 1) && (arr[i + 2] % 2 == 1)) {
        return true;
      }
    }
    return false;
  }
};


// class Solution {
//  public:
//   bool threeConsecutiveOdds(vector<int>& arr) {
//     int count = 0;
//     for ( int a : arr) {
//       count = a % 2 == 1 ? count + 1 : 0;
//       if (count == 3)
//         return true;
//     }
//     return false;
//   }
// };