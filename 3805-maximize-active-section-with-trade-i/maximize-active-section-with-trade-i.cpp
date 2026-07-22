class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        //existing count of 1s
        int active_count = count(begin(s), end(s), '1');

        vector<int> inactive_blocks;
        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;

                inactive_blocks.push_back(i-start);
            } else {
                i++;
            }
        }

        int max_pair_sum = 0;
        //max(inactive_blocks[i] + inactive_blocks[i-1])
        for(int i = 1; i < inactive_blocks.size(); i++) {
            max_pair_sum = max(max_pair_sum, inactive_blocks[i] + inactive_blocks[i-1]);
        }

        return max_pair_sum + active_count;
    }
};