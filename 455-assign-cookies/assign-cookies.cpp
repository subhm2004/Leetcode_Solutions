class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Greed array sort
        sort(s.begin(), s.end()); // Cookie array sort

        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // Bachha khush ho gaya
                i++;
            }
            // Har case me cookie to use ho jaayegi
            j++;
        }
        return i; // i children are content
    }
};
