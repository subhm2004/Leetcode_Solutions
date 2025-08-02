#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int min_element = INT_MAX;

        // Count net frequency difference and find the minimum element
        for (int x : basket1) {
            freq[x]++;
            min_element = min(min_element, x);
        }

        for (int x : basket2) {
            freq[x]--;
            min_element = min(min_element, x);
        }

        vector<int> excess;
        for (auto& [val, count] : freq) {
            if (count % 2 != 0) return -1; // If odd difference, impossible

            for (int i = 0; i < abs(count) / 2; ++i) {
                excess.push_back(val);
            }
        }

        sort(excess.begin(), excess.end()); 

        long long ans = 0;
        for (int i = 0; i < excess.size() / 2; ++i) {
            ans += min(excess[i], 2 * min_element); 
        }

        return ans;
    }
};
