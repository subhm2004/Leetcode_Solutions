class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> colors(n, 0);
        vector<int> ans;
        int count = 0;

        for (auto &q : queries) {
            int idx = q[0];
            int color = q[1];

            // Purane color ki wajah se jo pairs bane hue the unhe hata do
            if (colors[idx] != 0) {
                if (idx > 0 && colors[idx] == colors[idx - 1])
                    count--;

                if (idx < n - 1 && colors[idx] == colors[idx + 1])
                    count--;
            }

            // Color update
            colors[idx] = color;

            // Naye color ki wajah se jo pairs ban rahe hain unhe add kar do
            if (idx > 0 && colors[idx] == colors[idx - 1])
                count++;

            if (idx < n - 1 && colors[idx] == colors[idx + 1])
                count++;

            ans.push_back(count);
        }

        return ans;
    }
};