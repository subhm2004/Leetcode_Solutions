class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> freq;
        long long ans = 0;

        for (auto &w : words) {
            string same = w;
            int shift = w[0] - 'a';   // first char ko 'a' banane ke liye kitna shift

            for (int i = 0; i < w.size(); i++) {
                same[i] = ( (w[i] - 'a' - shift + 26) % 26 ) + 'a';
            }

            ans += freq[same];  // pehle kitne same pattern ke words dekhe
            freq[same]++;       // current word ko count me add
        }

        return ans;
    }
};