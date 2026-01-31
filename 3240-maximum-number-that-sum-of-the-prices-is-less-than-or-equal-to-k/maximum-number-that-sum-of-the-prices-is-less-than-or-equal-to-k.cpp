typedef long long ll;

class Solution {
public:
    string s;  // Binary representation of number (without leading zeros)
    int x;     // Position multiplier (x, 2x, 3x, ... positions count hongi)
    
    // dp[idx][tight][started] = {count of numbers, accumulated price}
    // idx: current position in binary string (0-indexed from left)
    // tight: kya abhi tak upper bound follow kar rahe hain (0 or 1)
    // started: kya number actually start ho gaya ya sirf leading zeros hain (0 or 1)
    pair<ll, ll> dp[65][2][2];

    // Main DP function jo count aur price dono calculate karta hai
    pair<ll, ll> solve(int idx, bool tight, bool started) {
        
        // BASE CASE: Binary string khatam ho gayi
        if (idx >= s.size()) {
            // Agar number start hua tha (leading zeros nahi the)
            if (started) {
                return make_pair(1LL, 0LL);  // 1 number bana, price 0 (leaf node pe)
            }
            // Agar sirf leading zeros the (number hi nahi bana)
            else {
                return make_pair(0LL, 0LL);  // 0 numbers, 0 price
            }
        }

        // MEMOIZATION: Agar pehle calculate kar chuke hain to return karo
        // dp array mein -1 stored hai initially, agar -1 nahi hai matlab already computed
        if (dp[idx][tight][started].first != -1)
            return dp[idx][tight][started];

        ll count = 0;  // Is state se kitne total numbers ban sakte hain
        ll price = 0;  // Un sabhi numbers ka accumulated price

        // LIMIT calculation: Agar tight hai to current digit se zyada nahi rakh sakte
        // Example: n=6="110", idx=0 pe agar tight=true hai to limit=1 (kyunki s[0]='1')
        //          Agar tight=false to limit=1 (binary mein max digit 1 hi ho sakti hai)
        int limit = tight ? (s[idx] - '0') : 1;
        
        // Current position LSB (Least Significant Bit) se kitni dur hai
        // Example: s="110", idx=0 -> pos_from_LSB = 3 (rightmost se 3rd position)
        //          s="110", idx=1 -> pos_from_LSB = 2
        //          s="110", idx=2 -> pos_from_LSB = 1
        int pos_from_LSB = s.size() - idx;  // 1-indexed position from right

        // LOOP: Current position pe 0 ya 1 (limit tak) try karo
        for (int bit = 0; bit <= limit; bit++) {
            
            // UPDATED_TIGHT: Aage tight rahega ya nahi
            // Agar abhi tight=true hai AUR hum limit digit rakh rahe hain,
            // to aage bhi tight rahega (upper bound follow karte rahenge)
            // Example: n=6="110", idx=0, bit=1 (limit) -> aage bhi tight
            //          n=6="110", idx=0, bit=0 -> aage tight nahi (chota number ban raha)
            bool updated_tight = tight && (bit == limit);
            
            // UPDATED_STARTED: Number start ho gaya ya nahi
            // Agar pehle se started=true ya ab non-zero bit (1) rakh rahe hain
            // Example: "001" -> pehle 2 zeros ignore, jab 1 aaya tab started=true
            bool updated_started = started || (bit != 0);

            // RECURSIVE CALL: Agle position ke liye solve karo
            // Return: {count of numbers in subtree, accumulated price in subtree}
            auto [c, p] = solve(idx + 1, updated_tight, updated_started);
            
            // Subtree se aaye numbers ko add karo
            count += c;   // Total numbers mein add
            price += p;   // Total price mein add

            // CURRENT POSITION KA PRICE CONTRIBUTION
            // Agar ye position price mein count hoti hai, to add karo
            // Conditions:
            // 1. updated_started = true (number actually start ho gaya, leading zero nahi)
            // 2. bit = 1 (current position pe 1 hai)
            // 3. pos_from_LSB % x == 0 (position x ka multiple hai)
            //
            // Logic: Agar current position "special" hai (x, 2x, 3x, ...),
            //        aur yahan 1 hai, to subtree ke SABHI numbers mein +1 price add hoga
            // Example: x=1, pos=3, bit=1 -> pos%1==0 ✓
            //          Subtree mein agar 5 numbers hain, to sabko +1 price milega
            //          Isliye price += c (c = count of numbers in subtree)
            if (updated_started && bit == 1 && pos_from_LSB % x == 0) {
                price += c;  // Subtree ke har number ka price +1 ho gaya
            }
        }

        // MEMOIZE: Result store karo aur return karo
        return dp[idx][tight][started] = {count, price};
    }

    // Function to calculate accumulated price from 1 to n
    ll accumulate_price(ll n) {
        
        // EDGE CASE: Agar n <= 0 to accumulated price 0 hai
        if (n <= 0)
            return 0;
        
        // BINARY CONVERSION: Number ko binary string mein convert karo
        // bitset<64> 64-bit binary representation deta hai
        // Example: n=6 -> "0000000000000000000000000000000000000000000000000000000000000110"
        s = bitset<64>(n).to_string();

        // REMOVE LEADING ZEROS: Pehla '1' dhundo aur usse string start karo
        // Example: "000...110" -> "110"
        int firstOne = s.find('1');  // Pehle '1' ka index
        s = s.substr(firstOne);      // Us index se lekar end tak substring

        // DP INITIALIZATION: Sabhi states ko -1 se initialize karo
        // -1 ka matlab hai "abhi calculate nahi kiya"
        // DP dimensions: [65 positions][2 tight values][2 started values]
        for (int i = 0; i < 65; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    dp[i][j][k] = {-1, -1};  // {count=-1, price=-1}

        // SOLVE: DP function call karo
        // Parameters:
        // - idx=0: Binary string ke start se shuru karo
        // - tight=true: Initially upper bound follow karna hai
        // - started=false: Abhi number start nahi hua (leading zeros possible)
        // Return: {total count, total accumulated price}
        // Humein sirf price chahiye, so .second return karo
        return solve(0, true, false).second;
    }

    // Main function: Greatest cheap number find karo
    long long findMaximumNumber(long long k, int x) {
        this->x = x;  // Global x set karo taaki solve() use kar sake

        // BINARY SEARCH setup
        ll low = 1;        // Minimum possible answer
        ll high = 1e15;    // Maximum possible answer (constraint se)
        ll ans = 0;        // Result store karne ke liye

        // BINARY SEARCH: Answer monotonic hai
        // Agar n cheap hai, to n-1 bhi cheap hai
        // Agar n expensive hai, to n+1 bhi expensive hai
        // Isliye binary search laga sakte hain
        while (low <= high) {
            ll mid = low + (high - low) / 2;  // Overflow avoid karne ke liye
            
            // Mid number tak ka accumulated price check karo
            if (accumulate_price(mid) <= k) {
                // Agar cheap hai (accumulated_price <= k)
                ans = mid;          // Current mid answer ho sakta hai
                low = mid + 1;      // Aur bada number try karo (right half)
            } else {
                // Agar expensive hai (accumulated_price > k)
                high = mid - 1;     // Chota number try karo (left half)
            }
        }
        
        // RETURN: Sabse bada cheap number
        return ans;
    }
};

/*
EXAMPLE TRACE for n=6, x=1:

Binary of 6 = "110"

solve(0, tight=1, started=0):
    pos_from_LSB = 3
    limit = 1 (s[0]='1')
    
    bit=0:
        solve(1, tight=0, started=0)  // "0__"
        Returns some {count_0, price_0}
    
    bit=1:
        solve(1, tight=1, started=1)  // "1__"
        pos_from_LSB=3, 3%1==0, bit=1, started=1
        price += count from subtree
        Returns some {count_1, price_1}
    
    Final: {count_0 + count_1, price_0 + price_1 + count_1}

Numbers from 1 to 6:
1 = 001 -> pos 1: price=1
2 = 010 -> pos 2: price=1
3 = 011 -> pos 1,2: price=2
4 = 100 -> pos 3: price=1
5 = 101 -> pos 1,3: price=2
6 = 110 -> pos 2,3: price=2

Accumulated price = 1+1+2+1+2+2 = 9
*/