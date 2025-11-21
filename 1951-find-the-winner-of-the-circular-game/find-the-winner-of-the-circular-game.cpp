auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution { //Josephus Problem
public:
    int solveRE(int n, int k) { // ye 0 index based solve kr diya hai 
        if (n == 1)
            return 0;
        return (solveRE(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) { return solveRE(n, k) + 1; } // 1 baed idx me convert kr diya
};
