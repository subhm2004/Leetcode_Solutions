class Solution {
public:
    vector<int> ans;

    void solve(string& num, int idx, bool tight, bool started, int prev_digit,
               long long curr) {

        if (idx == num.size()) {
            if (started)
                ans.push_back(curr);
            return;
        }

        int limit = tight ? num[idx] - '0' : 9;

        for (int digit = 0; digit <= limit; digit++) {

            bool updated_tight = tight && (digit == limit);
            bool updated_started = started || (digit != 0);

            // Abhi bhi leading zeros chal rahe hain
            if (!updated_started) {

                solve(num, idx + 1, updated_tight, updated_started, -1, 0);
            }

            // Number abhi start hua
            else if (!started) {

                solve(num, idx + 1, updated_tight, updated_started, digit, digit);
            }

            // Number pehle se start ho chuka hai
            else {

                // Next digit sequential hona chahiye
                if (digit == prev_digit + 1) {

                    solve(num, idx + 1, updated_tight, updated_started, digit, curr * 10 + digit);
                }
            }
        }
    }

    vector<int> generate(int x) {

        ans.clear();

        string s = to_string(x);

        solve(s, 0, true, false, -1, 0);

        sort(ans.begin(), ans.end());

        return ans;
    }

    vector<int> sequentialDigits(int low, int high) {

        vector<int> high_numbers = generate(high);

    vector<int> ans;

    for (int num : high_numbers) {

        if (num >= low)
            ans.push_back(num);
    }

        return ans;
    }
};