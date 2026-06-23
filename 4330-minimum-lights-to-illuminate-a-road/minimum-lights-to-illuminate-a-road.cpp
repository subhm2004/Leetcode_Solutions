class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        // Difference array banayi hai existing bulbs ki coverage mark karne ke liye.
        // diff[i] batayega ki position i par kitni lights ki coverage start/end ho rahi hai.
        vector<int> diff(n, 0);

        // Existing working bulbs ki illuminated range mark kar rahe hain.
        for (int i = 0; i < n; i++) {

            // Agar position i par bulb hai.
            if (lights[i] > 0) {

                // Bulb ki leftmost coverage.
                int l = max(0, i - lights[i]);

                // Bulb ki rightmost coverage.
                int r = min(n - 1, i + lights[i]);

                // Difference array me range add kar do.
                diff[l] += 1;

                // Range ke end ke baad coverage hata do.
                if (r + 1 < n)
                    diff[r + 1] -= 1;
            }
        }

        // Difference array ko prefix sum me convert kar rahe hain.
        // Ab diff[i] > 0 ka matlab position i already illuminated hai.
        for (int i = 1; i < n; i++)
            diff[i] = diff[i] + diff[i - 1];

        int ans = 0;

        // Road ko left se right traverse karenge.
        for (int i = 0; i < n; i++) {

            // Agar:
            // 1. Yahan pe pehle se koi working bulb nahi hai.
            // 2. Ye position kisi bhi bulb se illuminate nahi ho rahi.
            if (lights[i] == 0 && diff[i] == 0) {

                // Ek naya bulb lagana padega.
                ans++;

                // Greedy approach:
                // Hum maan rahe hain bulb i+1 par lagaya gaya hai
                // (ya effectively i, i+1, i+2 ko cover kar diya).
                //
                // Radius 1 bulb maximum 3 positions cover karta hai:
                // [i, i+1, i+2]
                //
                // Isliye in positions ko visible mark kar dete hain.

                diff[i] = 1;

                if (i + 1 < n)
                    diff[i + 1] = 1;

                if (i + 2 < n)
                    diff[i + 2] = 1;
            }
        }

        // Minimum additional bulbs required.
        return ans;
    }
};