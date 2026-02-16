class Solution {
public:
    int reverseBits(int n) {
        string str = bitset<32>(n).to_string();
        reverse(str.begin(), str.end());
        return stoi(str, 0, 2);
    }
};// stoi(string, ending pos pointer, base)
