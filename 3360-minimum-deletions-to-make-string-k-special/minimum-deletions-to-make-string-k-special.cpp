class Solution {
public:
    int minimumDeletions(string word, int k) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char ch : word) {
            freq[ch]++;
        }

        // Step 2: Store frequencies in a vector
        vector<int> counts;
        for (auto& [ch, f] : freq) {
            counts.push_back(f);
        }

        int ans = INT_MAX;

        // Step 3: Try every possible target frequency from 1 to max freq
        for (int target = 1; target <= *max_element(counts.begin(), counts.end()); ++target) {
            int deletions = 0;

            for (int f : counts) {
                if (f < target) {
                    // If freq is too low, delete entire character
                    deletions += f;
                } else if (f > target + k) {
                    // If freq is too high, delete extras
                    deletions += f - (target + k);
                }
                // If freq is between [target, target + k], do nothing
            }

            ans = min(ans, deletions);
        }

        return ans;
    }
};
