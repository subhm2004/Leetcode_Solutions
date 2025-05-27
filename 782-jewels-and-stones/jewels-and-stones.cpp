#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each stone
        for (char c : stones) {
            freq[c]++;
        }

        int ans = 0;

        // Step 2: Check each jewel type in the map
        for (char jewel : jewels) {
            ans += freq[jewel];
        }

        return ans;
    }
};
