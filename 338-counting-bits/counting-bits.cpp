class Solution {
public:
    int count_set_bits(int n){ // Brian Kernighan's Algorithm 
        int count = 0;
        while (n!= 0){
            n = (n&(n-1)); // Remove Last Set Bit
            count++;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            // ans[i] = __builtin_popcount(i);
            // ans[i] = count_set_bits(i);
            ans[i] = ans[i>>1] + (i&1);
        }
        return ans;
    }
};
