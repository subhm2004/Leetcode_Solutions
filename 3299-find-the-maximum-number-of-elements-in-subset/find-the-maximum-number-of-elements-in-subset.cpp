class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            if (freq[1] % 2)
                ans = max(ans, freq[1]);
            else
                ans = max(ans, freq[1] - 1);
        }

        for (auto &it : freq) {
            long long x = it.first;

            if (x == 1)
                continue;

            int len = 1;
            long long curr_val = x;

            while (true) {
                if (freq[curr_val] < 2)
                    break;

                long long next_val = curr_val * curr_val;

                if (!freq.count(next_val))
                    break;

                len += 2;
                curr_val = next_val;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};