using ll = long long;
class Solution {
public:
    bool is_Possible(ll target, int m, vector<int>& points, int n) {
        ll moves = 0;

        ll advance_Games_To_Next = 0;
        ll normal_Move = 0;

        for (int i = 0; i < n && moves <= m; i++) {
            int game_Point = points[i];

            ll games = (target + game_Point - 1) / game_Point;
            // cile(a/b) = (a + b - 1) / b

            if (advance_Games_To_Next >= games) {
                advance_Games_To_Next = 0;
                normal_Move += 1;
            } else {
                ll points_Already_Covered = advance_Games_To_Next * game_Point;

                games = (target - points_Already_Covered + game_Point - 1) /
                        game_Point;
                // ceil((target - points_Already_Covered) / game_Point);

                moves += (2 * games) - 1;

                advance_Games_To_Next = max(games - 1, 0LL);

                moves += normal_Move;

                normal_Move = 0;
            }
        }

        return moves <= m;
    }

    long long maxScore(vector<int>& points, int m) {
        int n = points.size();

        ll l = 1;
        ll r = 1e15; // 10^9 * 10^6 = 10^15

        ll ans = 0;

        while (l <= r) {
            ll mid = l + (r - l) / 2; // target score

            if (is_Possible(mid, m, points, n) == true) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};