class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> count;  // Har number ka count rakhne ke liye map
        vector<int> ans(2);  // Pair count aur leftover count ko store karne ke liye

        // Har number ka count karte hain
        for (int num : nums) {
            count[num]++;
        }

        // Pairs aur leftovers calculate karte hain
        for (const auto& entry : count) {
            ans[0] += entry.second / 2;  // Pairs ka count kar rahe hain
            ans[1] += entry.second % 2;  // Leftovers ka count kar rahe hain
        }

        return ans;  // Final result (pairs aur leftovers)
    }
};