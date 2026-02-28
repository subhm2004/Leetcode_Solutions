class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> freq;

        // frequency count
        for (int x : nums)
            freq[x]++;

        // check all pairs
        for (auto const& [v1, f1] : freq) {

            for (auto const& [v2, f2] : freq) {

                // distinct values + different frequency
                if (v1 < v2 && f1 != f2) {
                    return {v1, v2};
                }
            }
        }

        return {-1, -1};
    }
};