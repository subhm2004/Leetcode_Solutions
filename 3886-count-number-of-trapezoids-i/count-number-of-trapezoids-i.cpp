class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long count_pairs(long long n) {
        if (n < 2) return 0;
        return (n * (n - 1)) / 2;
    }

    long long my_pow(long long base, long long exp) {
        long long ans = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return ans;
    }

    long long MOD_inverse(int a) {
        return my_pow(a, MOD - 2);
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> y_to_point_count;
        for (auto& point : points) {
            int y = point[1];
            y_to_point_count[y]++;
        }

        vector<long long> line_pairs;
        for (auto& [y, count] : y_to_point_count) {
            if (count >= 2) {
                line_pairs.push_back(count_pairs(count));
            }
        }

        if (line_pairs.size() < 2) return 0;

        long long total_sum = 0;
        long long square_sum = 0;

        for (auto pairs : line_pairs) {
            pairs %= MOD;
            total_sum = (total_sum + pairs) % MOD;
            square_sum = (square_sum + (pairs * pairs) % MOD) % MOD;
        }

        long long total_ways = (total_sum * total_sum) % MOD;
        long long numerator = (total_ways - square_sum + MOD) % MOD;
        long long ans = (numerator * MOD_inverse(2)) % MOD;

        return (int) ans;
    }
};
