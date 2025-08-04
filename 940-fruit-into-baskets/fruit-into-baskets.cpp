class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int, int> mp;

        int ans = 0;
        int left = 0;

        for (int right = 0; right < arr.size(); right++) {
            mp[arr[right]]++;

            while (mp.size() > 2) {
                if (--mp[arr[left]] == 0)
                    mp.erase(arr[left]);

                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
