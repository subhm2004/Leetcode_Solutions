// https://www.youtube.com/watch?v=1lLmo2aC29o
typedef unsigned long long ull;
class Solution {
public:
    ull solveRE(ull i, ull jump, bool canGoBack, ull K, vector<long long>& power) {
        // Agar i K+1 se zyada ho gaya, toh valid move nahi hai
        if (i > K + 1)
            return 0;

        ull ans_ways = 0;

        // Agar hum K-th stair pe pahuch gaye hain, toh ans_ways ko increment kar lo
        if (i == K) {
            ans_ways++;  // Hum yahan ruk bhi sakte hain, ya agle moves bhi try kar sakte hain
        }

        // Agar hum back jaa sakte hain (canGoBack = true ), toh ek step neeche chalne ki koshish karo
        if (canGoBack == true) {
            ans_ways += solveRE(i - 1, jump, false , K, power);  // Neeche jao aur canGoBack ko 0 kar do
        }

        // Jump up karte hain 2^jump distance ke hisaab se, aur phir back jaane ki permission de dete hain
        ans_ways += solveRE(i + power[jump], jump + 1, true , K, power);

        return ans_ways;  // Total possible ways return karo
    }


    ull solveME(ull i, ull jump, bool canGoBack, ull K, vector<long long>& power, unordered_map<string, ull>& dp) {
        if (i > K + 1)
            return 0;

        auto key = to_string(i) + "_" + to_string(jump) + "_" + to_string(canGoBack);

        if (dp.find(key) != dp.end())
            return dp[key];

        ull ans_ways = 0;

        if (i == K) {
            ans_ways++;
        }

        if (canGoBack == true ) {
            ans_ways += solveME(i - 1, jump, false , K, power, dp);
        }

        ans_ways += solveME(i + power[jump], jump + 1, true , K, power, dp);

        return dp[key] = ans_ways;
    }

    ull waysToReachStair(ull k) {
        unordered_map<string, ull> dp;

        vector<long long> power(64);  
        
        for (ull i = 0; i < 64; ++i) {
            // power[i] = pow(2, i);
            power[i] = (1LL << i);  // 2^i
        }

        // return solveRE(1, 0, 1, k, power); 
        return solveME(1, 0, 1, k, power, dp);

    }
};