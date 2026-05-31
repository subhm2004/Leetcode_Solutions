class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> freq;

        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }

        int ans = 0;

        for (auto &[digit, count] : freq) {
            ans += digit * count;
        }

        return ans;
    }
};