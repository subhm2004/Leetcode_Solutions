class Solution {
 public:
    int count_set_Bits(int n) { // Brian Kernighan’s Algorithm
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [this](int a, int b) { 
    int bitsA = count_set_Bits(a);  
    int bitsB = count_set_Bits(b);
      return bitsA == bitsB ? a < b : bitsA < bitsB;
    });
    return arr;
  }
};
