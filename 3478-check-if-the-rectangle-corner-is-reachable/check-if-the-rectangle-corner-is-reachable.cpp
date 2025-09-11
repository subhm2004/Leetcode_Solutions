typedef long long ll;
class Solution {
private:
    vector<vector<int>> circles;
    int xCorner, yCorner;
    vector<bool> visited;

    bool in_circle(ll x, ll y, ll cx, ll cy, ll r) {
        return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
    }

    bool cross_Left_Top(ll cx, ll cy, ll r) {
        bool a = abs(cx - 0) <= r && (cy >= 0 && cy <= yCorner);
        bool b = abs(cy - yCorner) <= r && (cx >= 0 && cx <= xCorner);
        return a || b;
    }

    bool cross_Right_Bottom(ll cx, ll cy, ll r) {
        bool a = abs(cx - xCorner) <= r && (cy >= 0 && cy <= yCorner);
        bool b = abs(cy) <= r && (cx >= 0 && cx <= xCorner);
        return a || b;
    }

    bool dfs(int i) {
        auto c = circles[i];
        ll x1 = c[0], y1 = c[1], r1 = c[2];
        if (cross_Right_Bottom(x1, y1, r1)) {
            return true;
        }
        visited[i] = true;
        for (int j = 0; j < circles.size(); ++j) {
            auto c2 = circles[j];
            ll x2 = c2[0], y2 = c2[1], r2 = c2[2];
            if (visited[j]) {
                continue;
            }
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
                continue;
            }
            if (x1 * r2 + x2 * r1 < (r1 + r2) * xCorner &&
                y1 * r2 + y2 * r1 < (r1 + r2) * yCorner &&
                dfs(j)) {
                return true;
            }
        }
        return false;
    }

public:
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        int n = circles.size();
        this->circles = circles;
        this->xCorner = xCorner;
        this->yCorner = yCorner;
        visited.resize(n, false);

        for (int i = 0; i < n; ++i) {
            auto c = circles[i];
            int x = c[0], y = c[1], r = c[2];
            if (in_circle(0, 0, x, y, r) || in_circle(xCorner, yCorner, x, y, r)) {
                return false;
            }
            if (!visited[i] && cross_Left_Top(x, y, r) && dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
