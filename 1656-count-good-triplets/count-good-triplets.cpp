class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n - 2; ++i) {
            int x = arr[i];
            for (int j = i + 1; j < n - 1; ++j) {
                int y = arr[j];
                if (abs(x - y) > a) continue;  // early cut
                for (int k = j + 1; k < n; ++k) {
                    int z = arr[k];
                    if (abs(y - z) <= b && abs(x - z) <= c)
                        ++ans;
                }
            }
        }
        return ans;
    }
};
