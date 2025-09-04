class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int k = (-1 + sqrt(1 + 8 * n)) / 2;
        return k;
    }
};