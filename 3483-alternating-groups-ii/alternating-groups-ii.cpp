class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, count = 0;

        // Circular array ka 2x traverse kar rahe hain taaki pura cycle cover ho
        for (int i = 0; i < 2 * n; ++i) {
            // Agar pichla color same hai, to alternating group yahan break ho
            // raha hai
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                count = 1; // Count ko reset kar diya
            } else {
                ++count; // Alternating sequence continue ho rahi hai, to count
                         // badha diya
            }

            // Jab `i` n se bada ho jaye aur current sequence ka length `k` ya
            // usse zyada ho
            if (i >= n && count >= k) {
                ++ans; // Valid alternating group mil gaya, answer badha diya
            }
        }
        return ans;
    }
};