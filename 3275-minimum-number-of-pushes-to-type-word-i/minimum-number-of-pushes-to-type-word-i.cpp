class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> mp;

        int ans = 0;
        int key = 2;

        for (char ch : word) {
            if (key > 9)
                key = 2;

            mp[key]++;
            ans += mp[key];

            key++;
        }

        return ans;
    }
};