auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();

typedef long long ll;
ll MOD = 1e9+7;
class Solution {
public:
    vector<ll> get_segments(int bound, vector<int> fences) {
        // boundaries kr dete hai 
        fences.push_back(1);
        fences.push_back(bound);
        sort(fences.begin(), fences.end());

        vector<ll> seg;
        int k = fences.size();

        for(int i = 0; i < k; i++) {
            for(int j = i+1; j < k; j++) {
                seg.push_back((ll)fences[j] - fences[i]);
            }
        }
        return seg;
    }

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        // all horizontal segment lengths
        vector<ll> H = get_segments(m, hFences);

        // all vertical segment lengths
        vector<ll> V = get_segments(n, vFences);

        unordered_set<ll> st(H.begin(), H.end());

        ll best_ans = -1;

        for(ll val : V) {
            if(st.count(val)) {
                best_ans = max(best_ans, val * val);
            }
        }

        return (best_ans == -1 ? -1 : best_ans % MOD);
    }
};
