class Solution {
public:
    // int number_of_bits(int x) {
    //     int count = 0;
    //     while (x) {
    //         x >>= 1; // divide x by 2 (bitwise)
    //         count++; // count how many times we can divide until x becomes 0
    //     }
    //     return count;
    // }
    int number_of_bits(int x) { return x == 0 ? 0 : (int)std::log2(x) + 1; }

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return n;
        int numOfBits = number_of_bits(n);
        return pow(2, numOfBits);
    }
};
