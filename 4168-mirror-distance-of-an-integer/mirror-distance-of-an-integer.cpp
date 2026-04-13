class Solution {
public:
    int reversed_number(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);
    }

    int mirrorDistance(int n) {
        int reversed = reversed_number(n);
        return abs(n - reversed);
    }
};