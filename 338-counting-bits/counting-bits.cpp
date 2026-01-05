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



/*

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        if(n == 0)
            return ans;
        
        ans[1] = 1;
        
        for(int i = 2; i < n+1; i++) {
            
            if(i%2 == 0) {
                ans[i] = ans[i/2];
            } else {
                ans[i] = ans[i/2] + 1;
            }
            
        }
        
        return ans;
        
    }
};





*/