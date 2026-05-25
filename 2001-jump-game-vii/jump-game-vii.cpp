class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        // dp[i] = 1 means index i reachable hai, 0 means nahi
        vector<int> dp(n, 0);
        dp[0] = 1; // index 0 se start karte hain
        
        // count = current sliding window mein kitne reachable indices hain
        int count = 0;
        
        for(int j = 1; j <= n-1; j++) {
            
            // j - minJump window mein enter kar raha hai (right boundary)
            if(j - minJump >= 0) {
                count += dp[j - minJump];
            }
            
            // j - maxJump - 1 window se bahar ja raha hai (left boundary)
            if(j - maxJump - 1 >= 0) {
                count -= dp[j - maxJump - 1];
            }
            
            // agar window mein koi reachable index hai AND s[j] == '0'
            // tabhi j tak pahunch sakte hain
            if(count > 0 && s[j] == '0') {
                dp[j] = 1;
            }
        }
        
        // last index reachable hai ya nahi
        return dp[n-1] > 0;
    }
};