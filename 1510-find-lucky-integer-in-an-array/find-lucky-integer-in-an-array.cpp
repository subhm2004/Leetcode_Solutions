class Solution {
 public:
  int findLucky(vector<int>& arr) {
    vector<int> count(501, 0);

    for (int num : arr) {
      if (num <= 500)
        ++count[num];
    }

    for (int i = 500; i >= 1; --i) {
      if (count[i] == i)
        return i;
    }

    return -1;
  }
};
