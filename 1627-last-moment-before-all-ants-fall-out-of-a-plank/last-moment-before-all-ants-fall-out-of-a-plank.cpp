class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_left  = left.empty()  ? 0 : *max_element(left.begin(), left.end());
        int max_right = right.empty() ? 0 : n - *min_element(right.begin(), right.end());
        return max(max_left, max_right);
    }
};
