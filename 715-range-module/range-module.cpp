class RangeModule {
public:
    vector<int> A;

    void addRange(int left, int right) {
        auto i = lower_bound(A.begin(), A.end(), left) - A.begin();
        auto j = upper_bound(A.begin(), A.end(), right) - A.begin();

        vector<int> newRange;
        if (i % 2 == 0) newRange.push_back(left);
        if (j % 2 == 0) newRange.push_back(right);

        A.erase(A.begin() + i, A.begin() + j);
        A.insert(A.begin() + i, newRange.begin(), newRange.end());
    }

    bool queryRange(int left, int right) {
        auto i = upper_bound(A.begin(), A.end(), left) - A.begin();
        auto j = lower_bound(A.begin(), A.end(), right) - A.begin();
        return i == j && i % 2 == 1;
    }

    void removeRange(int left, int right) {
        auto i = lower_bound(A.begin(), A.end(), left) - A.begin();
        auto j = upper_bound(A.begin(), A.end(), right) - A.begin();

        vector<int> newRange;
        if (i % 2 == 1) newRange.push_back(left);
        if (j % 2 == 1) newRange.push_back(right);

        A.erase(A.begin() + i, A.begin() + j);
        A.insert(A.begin() + i, newRange.begin(), newRange.end());
    }
};
