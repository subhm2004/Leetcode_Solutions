// class Solution {       // TLE 513/792
// public:
//     void backtrack(string& num, vector<bool>& visited, string& current, int& count) {
//         // Base Case
//         if (current.size() == num.size()) {
//             int even_Sum = 0, odd_Sum = 0;
//             for (int i = 0; i < current.size(); ++i) {
//                 int digit = current[i] - '0';
//                 if (i % 2 == 0) even_Sum += digit;
//                 else odd_Sum += digit;
//             }
//             if (even_Sum == odd_Sum) count++;
//             return;
//         }

//         for (int i = 0; i < num.size(); ++i) {
//             if (visited[i]) continue;
//             // Skip duplicates: if current digit is same as previous and previous was not visited
//             if (i > 0 && num[i] == num[i - 1] && !visited[i - 1]) continue;

//             visited[i] = true;
//             current.push_back(num[i]);
//             backtrack(num, visited, current, count);
//             current.pop_back();
//             visited[i] = false;
//         }
//     }

//     int countBalancedPermutations(string num) {
//         sort(num.begin(), num.end()); // sort to help with duplicate permutations
//         vector<bool> visited(num.size(), false);
//         int count = 0;
//         string current;
//         backtrack(num, visited, current, count);
//         return count;
//     }
// };

class Combinatorics {
public:
    typedef long long ll;
    const int M = 1e9 + 7;
    const int N = 1e5 + 2;
    vector<ll> fact;

    ll mod(ll x) { return ((x % M + M) % M); }
    ll add(ll a, ll b) { return mod(a + b); }
    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b % 2) ans = mul(ans, a);
            a = mul(a, a);
            b /= 2;
        }
        return ans;
    }

    ll inv(ll x) { return modPow(x, M - 2); }
    ll modSub(ll a, ll b) { return mod(a - b); }
    ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

    Combinatorics() {
        fact.resize(N, 1);
        precalc();
    }

    void precalc() {
        for (int i = 1; i < N; i++) {
            fact[i] = mul(fact[i - 1], i);
        }
    }

    ll nCr(ll n, ll r) {
        if (r > n || r < 0) return 0;
        return mul(fact[n], mul(inv(fact[r]), inv(fact[n - r])));
    }

    ll factorial(ll r) {
        if (r < 0) return 0;
        return fact[r];
    }

    ll getDistinctWays(const string& word) {
        unordered_map<char, ll> freq;
        for (const auto& c : word) freq[c]++;
        ll ways = factorial(word.length());
        for (const auto& entry : freq) {
            ll count = entry.second;
            ways = mul(ways, inv(factorial(count)));
        }
        return ways;
    }
};

class Solution : public Combinatorics {
public:
    int n;
    int totalDigitSum;
    long long totalPermPossible = 0;

    // Optimized recursive solution using memoization
    long long solve(int digit, int evenIndexDigitsCount, int currSum, 
                     vector<int>& freq, vector<vector<vector<long long>>>& dp) {
        if (digit == 10) {
            if (currSum == totalDigitSum / 2 && evenIndexDigitsCount == (n + 1) / 2) {
                return totalPermPossible;
            }
            return 0;
        }

        if (dp[digit][evenIndexDigitsCount][currSum] != -1) {
            return dp[digit][evenIndexDigitsCount][currSum];
        }

        long long ways = 0;

        for (int count = 0; count <= min(freq[digit], (n + 1) / 2 - evenIndexDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount = freq[digit] - count;

            // Using combinations and factorials from the Combinatorics class
            long long divisor = mul(factorial(evenPosCount), factorial(oddPosCount));

            long long val = solve(digit + 1, evenIndexDigitsCount + evenPosCount, 
                                   currSum + digit * count, freq, dp);

            ways = add(ways, modDiv(val, divisor));
        }

        return dp[digit][evenIndexDigitsCount][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n = num.length();
        totalDigitSum = 0;

        // Frequency of digits in the input number
        vector<int> freq(10, 0);
        for (char ch : num) {
            int d = ch - '0';
            totalDigitSum += d;
            freq[d]++;
        }

        // If the total sum is odd, there can't be a balanced permutation
        if (totalDigitSum % 2 != 0) {
            return 0;
        }

        // Calculate the total number of possible permutations of the digits
        totalPermPossible = mul(factorial((n + 1) / 2), factorial(n / 2));

        // DP table initialization
        vector<vector<vector<long long>>> dp(10, vector<vector<long long>>((n + 1) / 2 + 1, 
            vector<long long>(totalDigitSum + 1, -1)));

        return solve(0, 0, 0, freq, dp);
    }
};
