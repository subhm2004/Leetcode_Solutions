class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        set<int> unique_values;

        // frequency + unique values
        for (int x : nums) {
            freq[x]++;
            unique_values.insert(x);
        }

        // set -> vector (sorted values)
        vector<int> values(unique_values.begin(), unique_values.end());

        // valid pair nikalte hai 
        for (int i = 0; i < values.size(); i++) {

            int x = values[i];

            for (int j = i + 1; j < values.size(); j++) {

                int y = values[j];

                if (freq[x] != freq[y])
                    return {x, y};
            }
        }

        return {-1, -1};
    }
};