class Solution {
public:
    vector<int> prefix;

    /* ═══════════════════════════════════════════════════════════════════════
       LOTTERY TICKET ANALOGY — poora concept yahi hai
       ───────────────────────────────────────────────────────────────────────
       Problem: har index ko uske weight ke hisaab se chance dena hai.
                Par rand() to sabko BARABAR chance deta hai. Kaise karein?

       Jawab: lottery chalao. Har index ko uske weight ke barabar TICKETS do.

       w = [1, 3, 2]

           index 0  →  weight 1  →  1 ticket    →  ticket no:  1
           index 1  →  weight 3  →  3 tickets   →  ticket no:  2, 3, 4
           index 2  →  weight 2  →  2 tickets   →  ticket no:  5, 6
                                                   ─────────────────────
                                                   TOTAL = 6 tickets

       Ab ek ticket BARABAR chance se uthao (1 se 6 me se koi bhi).
       Jiska ticket nikla, wahi jeeta.

           index 1 ke paas 3 tickets hain  →  wo 3/6 baar jeetega  ✓
           index 2 ke paas 2 tickets hain  →  wo 2/6 baar jeetega  ✓
           index 0 ke paas 1 ticket  hai   →  wo 1/6 baar jeetega  ✓

       PROBABILITY APNE AAP BAN GAYI — humne kahin 3/6 calculate nahi kiya,
       bas zyada weight wale ko zyada tickets de diye.

       Ab sirf ek sawal bacha:
           "Ticket number 5 nikla — ye KISKA ticket hai?"
       Iske liye prefix chahiye.
       ═══════════════════════════════════════════════════════════════════════ */

    /* ═══════════════════════════════════════════════════════════════════════
       Constructor: har index ka "AAKHRI ticket number" store karo
       ───────────────────────────────────────────────────────────────────────
       w      = [1, 3, 2]
       prefix = [1, 4, 6]
                 ↑  ↑  ↑
                 |  |  index 2 ka aakhri ticket = 6   (uske tickets: 5, 6)
                 |  index 1 ka aakhri ticket = 4      (uske tickets: 2, 3, 4)
                 index 0 ka aakhri ticket = 1         (uska ticket: 1)

       Har index ke tickets ka RANGE nikalna ho to:
           index i ke tickets  =  prefix[i-1] + 1  se  prefix[i]  tak
           (i = 0 ke liye  1 se prefix[0] tak)

       COMPLEX: O(n)
       ═══════════════════════════════════════════════════════════════════════ */
    Solution(vector<int>& w) {

        prefix.resize(w.size());

        prefix[0] = w[0];   /* pehle wale ka aakhri ticket = uska weight hi hai */

        /* har agla = pichla total + apna weight  (running sum) */
        for (int i = 1; i < w.size(); i++)
            prefix[i] = prefix[i - 1] + w[i];
    }

    /* ═══════════════════════════════════════════════════════════════════════
       pickIndex: ek ticket uthao, uske MALIK ka index return karo
       COMPLEX: O(n)
       ═══════════════════════════════════════════════════════════════════════ */
    int pickIndex() {

        /* prefix ka aakhri element = TOTAL tickets
           [1, 4, 6] → total = 6, matlab 6 tickets bante hain */
        int total = prefix.back();

        /* ── Ticket uthao: 1 se total tak, sab barabar chance ──
           General formula:  rand() % (max - min + 1) + min
             min = 1, max = total
             → rand() % (total - 1 + 1) + 1
             → rand() % total + 1                                          */
        int ticket = rand() % total + 1;

        /* ── Ab malik dhoondho ──
           Shuru se poochte jao: "kya ye ticket tere hisse me aata hai?"
           prefix[i] = i ka aakhri ticket number
           to  ticket <= prefix[i]  ka matlab: ticket i ke ANDAR hai.

           Pehla jo "HAAN" bole wahi malik hai — kyunki pichhle sab
           pehle hi "nahi" bol chuke, matlab unke tickets khatam ho gaye.

           DRY RUN (ticket = 5):
               i=0 :  5 <= 1  ?  NAHI  →  index 0 ke tickets khatam, aage
               i=1 :  5 <= 4  ?  NAHI  →  index 1 ke bhi khatam, aage
               i=2 :  5 <= 6  ?  HAAN  →  return 2   ✓

           DRY RUN (ticket = 3):
               i=0 :  3 <= 1  ?  NAHI  →  aage
               i=1 :  3 <= 4  ?  HAAN  →  return 1   ✓
                      (sahi hai — index 1 ke tickets 2, 3, 4 the)          */
        for (int i = 0; i < prefix.size(); i++) {

            if (ticket <= prefix[i])
                return i;
        }

        return -1;   /* yahan kabhi nahi pahunchega, kyunki ticket <= total hamesha */
    }
};