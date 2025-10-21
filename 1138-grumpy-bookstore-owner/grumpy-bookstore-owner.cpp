class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int already_satisfied = 0;

        // Step 1: Pehle un customers ka sum nikal lo jo already khush hain 
        // (matlab jaha owner grumpy nahi tha)
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                already_satisfied += customers[i];
            }
        }

        // Step 2: Ab sliding window lagao taaki wo window mil jaye
        // jisme owner grumpy tha lekin ab technique use karke unhe bhi khush kar sakte ho
        int extra_satisfied = 0;  // ye window ke andar wale grumpy customers ka sum rakhega
        int max_extra = 0;        // maximum extra satisfied customers store karega

        for (int i = 0; i < n; i++) {
            // Agar owner is minute grumpy tha, to un customers ko ab window me include karo
            if (grumpy[i] == 1) {
                extra_satisfied += customers[i];
            }

            // Jab window size 'minutes' se bada ho jaye,
            // to left side se element hata do (window ko slide karo) un element ko hatao jha pr wo grumpy tha
            if (i >= minutes) {
                if (grumpy[i - minutes] == 1) {
                    extra_satisfied -= customers[i - minutes];
                }
            }

            // Har step pe check karo ki maximum extra customers ab tak kitne ho sakte hain
            max_extra = max(max_extra, extra_satisfied);
        }

        // Total satisfied = jo pehle se khush the + jo window technique se khush hue
        return already_satisfied + max_extra;
    }
};

