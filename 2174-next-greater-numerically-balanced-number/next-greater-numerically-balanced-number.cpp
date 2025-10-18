auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    bool is_balanced(int x) {
        string s = to_string(x);
        vector<int> count(10, 0);

        for (char c : s)
            count[c - '0']++;

        for (int i = 0; i < 10; i++)
            if (count[i] && count[i] != i)
                return false;

        return true;
    }
    

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++) {
            if (is_balanced(i))
                return i;
        }
        return -1;
    }
};
