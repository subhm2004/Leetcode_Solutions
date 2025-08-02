class kadan {
public:
    int maxSubarraySum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
        }

        return max(0, maxi); // return 0 if all values are negative (empty string allowed)
    }
};

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> value_map;

        // Step 1: Build the value map
        for (int i = 0; i < chars.size(); ++i) {
            value_map[chars[i]] = vals[i];
        }

        // Step 2: Convert string s to cost array
        vector<int> costs;
        for (char c : s) {
            if (value_map.count(c)) {
                costs.push_back(value_map[c]);
            } else {
                costs.push_back(c - 'a' + 1);  // alphabet index value
            }
        }

        // Step 3: Use Kadane's Algorithm
        kadan solver;
        return solver.maxSubarraySum(costs);
    }
};
