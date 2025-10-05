class Solution {
public:
    int alternatingSum(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) sum += arr[i];   // even index → add
            else sum -= arr[i];              // odd index → subtract
        }
        return sum;
    }
};