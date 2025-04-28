class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        unordered_set<string> seen;

        for (const string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (seen.count(rev)) {
                ans++;
            }

            seen.insert(word); 
        }

        return ans;
    }
};