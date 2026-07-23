class Solution {
public:

    
    int number_of_bits(int x) { return x == 0 ? 0 : (int)log2(x) + 1; }

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return n;
        int no_of_bits = number_of_bits(n);
        return pow(2, no_of_bits);
    }
};
