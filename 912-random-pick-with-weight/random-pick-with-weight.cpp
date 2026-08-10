class Solution {
public:
    vector<int> prefix;

    // ════════════════════════════════════════════════════════════════
    // Constructor: har index ka "aakhri ticket number" nikal ke rakho
    // ────────────────────────────────────────────────────────────────
    // w      = [1, 3, 2]
    // prefix = [1, 4, 6]
    //           ↑  ↑  ↑
    //           |  |  index 2 ke tickets 6 tak (yaani 5,6)
    //           |  index 1 ke tickets 4 tak (yaani 2,3,4)
    //           index 0 ke tickets 1 tak (yaani sirf 1)
    //
    // COMPLEX: O(n)
    // ════════════════════════════════════════════════════════════════
    Solution(vector<int>& w) {

        prefix.resize(w.size());

        prefix[0] = w[0];   // pehla to seedha apna weight hi hai

        // har agla = pichla total + apna weight (running sum)
        for (int i = 1; i < w.size(); i++)
            prefix[i] = prefix[i - 1] + w[i];
    }

    // ════════════════════════════════════════════════════════════════
    // pickIndex: ek ticket uthao, uske malik ka index return karo
    // COMPLEX: O(n)  ← linear scan
    // ════════════════════════════════════════════════════════════════
    int pickIndex() {

        // prefix ka aakhri element = TOTAL tickets
        // ([1,4,6] me 6 → matlab 6 tickets bante hain)
        int total = prefix.back();

        // ── Ticket uthao: 1 se total tak, sab barabar chance ──
        // General formula: rand() % (max - min + 1) + min
        //   min = 1, max = total
        //   → rand() % (total - 1 + 1) + 1
        //   → rand() % total + 1
        int ticket = rand() % total + 1;

        // ── Malik dhoondho ──
        // Shuru se poochte jao: "kya ye ticket tere hisse me aata hai?"
        // prefix[i] = i ka aakhri ticket number
        // to ticket <= prefix[i] ka matlab: ticket i ke ANDAR hai
        //
        // Pehla jo "haan" bole, wahi malik hai — kyunki pichle sab
        // pehle hi "nahi" bol chuke, matlab unke tickets khatam ho gaye
        for (int i = 0; i < prefix.size(); i++) {

            if (ticket <= prefix[i])
                return i;
        }

        return -1;   // yahan kabhi nahi pahunchega (ticket <= total hamesha)
    }
};