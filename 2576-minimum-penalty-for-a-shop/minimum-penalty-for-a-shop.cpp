class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // Step 1: agar shop hamesha closed ho (j = 0)
        // to jitne 'Y' hain utni penalty lagegi
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y')
                penalty++;
        }

        int min_penalty = penalty;
        int best_closing_hour = 0;

        // Step 2: ek-ek hour shop open karte jao
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                // pehle closed tha, ab open -> penalty kam
                penalty--;
            } else {
                // customer nahi aaya, open rakhne ka nuksaan
                penalty++;
            }

            // agar naya penalty kam hai, update karo
            if (penalty < min_penalty) {
                min_penalty = penalty;
                best_closing_hour = i + 1; // i ke baad shop close hogi
            }
        }

        return best_closing_hour;
    }
};