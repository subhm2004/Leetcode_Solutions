class SegmentTree {
private:
    int n;
    vector<int> count, length;
    vector<int> sortedYCoords;

    void update(int node, int l, int r, int ul, int ur, int val) {
        if (r < ul || l > ur) return;

        if (ul <= l && r <= ur) {
            count[node] += val;
        } else {
            int mid = (l + r) / 2;
            update(2 * node + 1, l, mid, ul, ur, val);        // left child
            update(2 * node + 2, mid + 1, r, ul, ur, val);    // right child
        }

        if (count[node] > 0) {
            length[node] = sortedYCoords[r + 1] - sortedYCoords[l];
        } else if (l == r) {
            length[node] = 0;
        } else {
            length[node] = length[2 * node + 1] + length[2 * node + 2];
        }
    }

public:
    SegmentTree(const vector<int>& yCoords) {
        sortedYCoords = yCoords;
        n = sortedYCoords.size() - 1;
        count.assign(4 * n, 0);
        length.assign(4 * n, 0);
    }

    void update(int y1_idx, int y2_idx, int val) {
        update(0, 0, n - 1, y1_idx, y2_idx - 1, val);  // root index = 0
    }

    int query() const {
        return length[0];  // root index = 0
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7;
        vector<tuple<int, int, int, int>> events;
        set<int> y_coords;

        for (auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            events.emplace_back(x1, 1, y1, y2);
            events.emplace_back(x2, -1, y1, y2);
            y_coords.insert(y1);
            y_coords.insert(y2);
        }

        vector<int> ys(y_coords.begin(), y_coords.end());
        unordered_map<int, int> y_index;
        for (int i = 0; i < ys.size(); ++i) {
            y_index[ys[i]] = i;
        }

        SegmentTree st(ys);
        sort(events.begin(), events.end());

        long long result = 0;
        int prevX = get<0>(events[0]);

        for (auto& [x, type, y1, y2] : events) {
            result += 1LL * (x - prevX) * st.query();
            result %= MOD;
            st.update(y_index[y1], y_index[y2], type);
            prevX = x;
        }

        return result;
    }
};
