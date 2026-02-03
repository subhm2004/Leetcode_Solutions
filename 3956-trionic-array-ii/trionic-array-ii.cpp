class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const long long NEG = -4e18;  // ← Very negative value (impossible sum)
                                       // Iska matlab: "yahan valid subarray nahi hai"

        // -------- DP Arrays Initialize --------
        vector<long long> inc1(n, NEG);  // Phase 1: increasing part ka best sum
        vector<long long> dec2(n, NEG);  // Phase 1+2: inc+dec ka best sum
        vector<long long> inc3(n, NEG);  // Phase 1+2+3: complete trionic ka best sum

        // -------- Har index pe DP update karo --------
        for (int i = 1; i < n; i++) {  // i=1 se start kyunki hum i-1 se compare karenge

            // ================================================================
            // PHASE 1: STRICTLY INCREASING PART
            // ================================================================
            if (nums[i - 1] < nums[i]) {  // Agar strictly increasing hai
                
                // Option 1: NAYA sequence start karo sirf [i-1, i] se
                long long start_new = (long long)nums[i - 1] + nums[i];
                
                // Option 2: Pehle se chal raha increasing sequence EXTEND karo
                long long extend = NEG;  // Default: extend nahi kar sakte
                if (inc1[i - 1] != NEG)  // Agar i-1 pe valid inc1 tha
                    extend = inc1[i - 1] + nums[i];  // Toh usmein nums[i] add karo
                
                // Dono options mein se best lo
                inc1[i] = max(start_new, extend);
            }

            // ================================================================
            // PHASE 2: STRICTLY DECREASING PART
            // ================================================================
            if (nums[i - 1] > nums[i]) {  // Agar strictly decreasing hai
                
                // Best previous sum find karo (jo Phase 1 complete kar chuka hai)
                long long best_prev = NEG;
                
                // Option 1: Agar i-1 pe pehle se decreasing chal raha tha
                if (dec2[i - 1] != NEG)
                    best_prev = dec2[i - 1];
                
                // Option 2: Agar i-1 pe Phase 1 complete hua tha (inc1)
                // Toh wahan se Phase 2 START kar sakte hain
                if (inc1[i - 1] != NEG)
                    best_prev = max(best_prev, inc1[i - 1]);
                
                // Best previous sum mein nums[i] add karo
                if (best_prev != NEG)
                    dec2[i] = best_prev + nums[i];
            }

            // ================================================================
            // PHASE 3: STRICTLY INCREASING AGAIN (Final Phase)
            // ================================================================
            if (nums[i - 1] < nums[i]) {  // Agar strictly increasing hai
                
                // Best previous sum find karo (jo Phase 1+2 complete kar chuka hai)
                long long best_prev = NEG;
                
                // Option 1: Agar i-1 pe pehle se Phase 3 chal raha tha
                if (inc3[i - 1] != NEG)
                    best_prev = inc3[i - 1];
                
                // Option 2: Agar i-1 pe Phase 2 complete hua tha (dec2)
                // Toh wahan se Phase 3 START kar sakte hain
                if (dec2[i - 1] != NEG)
                    best_prev = max(best_prev, dec2[i - 1]);
                
                // Best previous sum mein nums[i] add karo
                if (best_prev != NEG)
                    inc3[i] = best_prev + nums[i];
            }
        }

        // -------- Final Answer: Sabse best inc3 dhundo --------
        long long ans = NEG;
        for (int i = 0; i < n; i++)
            ans = max(ans, inc3[i]);  // Kisi bhi index pe complete trionic ka max

        return ans;
    }
};