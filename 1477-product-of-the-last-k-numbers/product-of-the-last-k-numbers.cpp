class ProductOfNumbers {
public:
    vector<int> s;

    ProductOfNumbers() { s = {1}; }

    void add(int num) {
        if (num == 0)
            s = {1}; // Reset on zero
        else
            s.push_back(s.back() * num);
    }

    int getProduct(int k) {
        return k < s.size() ? s.back() / s[s.size() - k - 1] : 0;
    }
};
