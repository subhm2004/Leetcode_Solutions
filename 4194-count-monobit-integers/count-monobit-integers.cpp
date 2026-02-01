class Solution {
public:
    int countMonobit(int n) {
        return 1 + floor(log2(n + 1));
 }
};