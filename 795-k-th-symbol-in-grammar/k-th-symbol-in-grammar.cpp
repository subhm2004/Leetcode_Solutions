class Solution {
public:
   int solve(int N, int K) {
        if(N == 1 && K == 1)
            return 0;
        int length = pow(2, N-1);
        int mid = length/2;
        
        if(K <= mid)
            return solve(N-1, K);
        
        // return !solve(N-1, K-mid);
        return 1-solve(N-1, K-mid);

    }
    
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};