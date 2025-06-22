class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        // LINE 1: Function ka definition
        // Input: numWays - 1-indexed array jisme numWays[i] = amount i banane ke ways
        // Output: coin denominations ka vector jo ye pattern bana sake
        
        const int LIMIT = INT_MAX;  
        // LINE 2: Overflow se bachne ke liye limit set kiya
        // Kyun? DP calculations mein integer overflow na ho jaye
        // Agar dp[j] isse zyada ho jaye, toh hum ise cap kar denge
        
        int n = numWays.size();
        // LINE 3: Original array ka size nikala
        // Example: agar numWays = [0,1,0,2], toh n = 4
        
        // Step 1: 1-indexed banane ke liye convert kiya
        numWays.insert(numWays.begin(), 1);  // numWays[0] = 1 (base case)
        // LINE 4-5: Beginning mein 1 insert kiya
        // PEHLE: numWays = [0,1,0,2]     (indices 0,1,2,3 matlab amounts 1,2,3,4)
        // BAAD:   numWays = [1,0,1,0,2]   (indices 0,1,2,3,4 matlab amounts 0,1,2,3,4)
        // Kyun? Ab numWays[i] directly "amount i banane ke ways" ko represent karta hai
        // numWays[0] = 1 matlab "amount 0 banane ka 1 way hai" (koi coin use nahi karna)
        
        vector<long long> dp(n + 1, 0);
        // LINE 6: DP array banaya jo track karega ki hum currently har amount ko kitne ways mein bana sakte hain
        // Size n+1 kyunki humne numWays mein ek element add kiya hai
        // Sabko 0 se initialize kiya (initially koi positive amount nahi bana sakte)
        
        dp[0] = 1;  // Amount 0 banane ka ek way hai
        // LINE 7: Base case - amount 0 banane ka exactly 1 way hai (koi coin use nahi karna)
        
        vector<int> coins;
        // LINE 8: Result vector jo store karega coin denominations jo humein mile
        
        for (int i = 1; i <= n; ++i) {
        // LINE 9: Har amount ko 1 se n tak process kar rahe hain
        // Hum amounts ko increasing order mein process kar rahe hain
        
            long long currentWays = dp[i];
            // LINE 10: Abhi tak hum amount i ko kitne ways mein bana sakte hain?
            // Initially ye sabke liye 0 hoga (i > 0 ke liye)
            
            long long requiredWays = numWays[i];
            // LINE 11: Amount i ko kitne ways mein banana chahiye?
            // Ye input array se aa raha hai
            
            if (currentWays > requiredWays) return {};
            // LINE 12: Sanity check - agar hum amount i ko required se zyada ways mein bana sakte hain
            // toh ye impossible hai (hum ways kam nahi kar sakte, sirf coins add kar sakte hain)
            // Example: agar amount 3 ko 5 ways mein bana sakte hain lekin sirf 2 ways chahiye → impossible
            
            if (currentWays == requiredWays) continue;
            // LINE 13: Agar already exact utne ways hain jitne chahiye,
            // toh is amount ke liye naya coin nahi chahiye, next amount pe jao
            
            if (currentWays + 1 == requiredWays) {
            // LINE 14: KEY INSIGHT! Agar humein amount i banane ke liye exactly 1 aur way chahiye,
            // toh humein coin denomination i add karna hoga
            // Kyun? Coin i add karne se exactly 1 naya way milega: coin i khud use karna
            
                coins.push_back(i);
                // LINE 15: Coin denomination i ko result mein add kiya
                
                // dp ko update karna hai naye coin i use karke
                for (int j = i; j <= n; ++j) {
                // LINE 16: Sabhi amounts >= i ke liye DP array update karo
                // i se start kiya kyunki coin i amounts < i banane mein help nahi kar sakta
                
                    dp[j] += dp[j - i];
                    // LINE 17: Coin i se jo naye ways bante hain unhe add karo
                    // dp[j - i] = amount (j - i) banane ke ways
                    // Har aise way + coin i = amount j banane ka naya way
                    // Example: agar dp[3] = 2 aur hum coin 2 add karte hain,
                    //          toh dp[5] += dp[3] (5 bana sakte hain: amount 3 banane ka koi bhi way + coin 2)
                    
                    if (dp[j] > LIMIT) dp[j] = LIMIT;
                    // LINE 18: Overflow se bachav
                    // Agar dp[j] bahut bada ho jaye, toh use cap kar do integer overflow se bachne ke liye
                }
            } else {
                return {};  // Invalid difference
                // LINE 19-20: Agar current aur required ways ka difference exactly 1 nahi hai,
                // toh humari greedy approach se fix nahi ho sakta
                // Example: agar currentWays = 2 aur requiredWays = 5,
                //          toh hum ek single coin add karke exactly 3 aur ways nahi bana sakte
            }
        }
        
        // Final safety check
        for (int i = 1; i <= n; ++i) {
        // LINE 21-22: Sabhi amounts process karne ke baad, solution verify karo
        
            if (dp[i] != numWays[i]) return {};
            // LINE 23: Double-check karo ki final DP array target se match kar raha hai
            // Agar kisi bhi amount ke liye galat number of ways hai, toh solution invalid hai
        }
        
        return coins;
        // LINE 24: Jo coin denominations mile hain unhe return karo
    }
};

/*
EXAMPLE WALKTHROUGH (HINGLISH MEIN):
Input: numWays = [0,1,0,2]

STEP 1: 1-indexed mein convert karo
numWays = [1,0,1,0,2]  // [amount_0, amount_1, amount_2, amount_3, amount_4]
n = 4
dp = [1,0,0,0,0]       // Initially sirf amount 0 ko 1 way mein bana sakte hain

STEP 2: Har amount ko process karo
i=1: currentWays=0, requiredWays=0 → currentWays==requiredWays → continue karo
i=2: currentWays=0, requiredWays=1 → currentWays+1==requiredWays → coin 2 add karo
     dp update karo: j=2 se 4 tak: dp[j] += dp[j-2]
     dp[2] += dp[0] = 0+1 = 1
     dp[3] += dp[1] = 0+0 = 0  
     dp[4] += dp[2] = 0+1 = 1
     dp = [1,0,1,0,1]

i=3: currentWays=0, requiredWays=0 → currentWays==requiredWays → continue karo
i=4: currentWays=1, requiredWays=2 → currentWays+1==requiredWays → coin 4 add karo
     dp update karo: j=4 ke liye: dp[4] += dp[0] = 1+1 = 2
     dp = [1,0,1,0,2]

STEP 3: Final check
dp[1]=0 == numWays[1]=0 ✓
dp[2]=1 == numWays[2]=1 ✓  
dp[3]=0 == numWays[3]=0 ✓
dp[4]=2 == numWays[4]=2 ✓

Result: coins = [2,4]

SAMJHAO SIMPLE WORDS MEIN:
- Humein pata karna hai ki konse coins use karke ye pattern bana sakte hain
- Har step mein check karte hain: kitne ways chahiye vs kitne ways abhi hain
- Agar exactly 1 way kam hai, toh us amount ka coin add kar dete hain
- Coin add karne se naye ways ban jate hain, so DP update kar dete hain
- End mein verify kar lete hain ki sab sahi hai ya nahi
*/