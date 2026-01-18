class Solution {
public:
    vector<int> get_powers(int base, int bound) {
        vector<int> arr;
        long long curr = 1;

        while (curr <= bound) {
            arr.push_back(curr);
            if (base == 1) break;
            curr *= base;
        }
        return arr;
    }

    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> pow_x = get_powers(x, bound);
        vector<int> pow_y = get_powers(y, bound);

        unordered_set<int> st;
        for (int a : pow_x) {
            for (int b : pow_y) {
                if (a + b <= bound) st.insert(a + b);
                else break;
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};
