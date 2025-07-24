class Solution {
public:
    // Ye function check karta hai ki given limit ke andar jobs ko distribute kiya ja sakta hai ya nahi
    bool canDistribute(int idx, const vector<int>& jobs, int k, int limit, vector<int>& workers) {
        if (idx == jobs.size()) {
            return true;  // Agar saari jobs assign ho gayi, to valid distribution mil gaya
        }

        // Har worker ko ek ek job assign karne ki koshish karte hain
        for (int i = 0; i < k; ++i) {
            if (workers[i] + jobs[idx] <= limit) {  // Agar current worker job le sakta hai
                workers[i] += jobs[idx];  // Job assign kar do

                if (canDistribute(idx + 1, jobs, k, limit, workers)) {  
                    return true;  // Agar aage ka distribution possible hai to return true
                }

                workers[i] -= jobs[idx];  // Backtrack: Job hata do

                // Pruning: Agar worker pehle empty tha aur yeh job nahi le saka,
                // to aage wale bhi nahi le sakenge, isliye yahin break kar do
                if (workers[i] == 0) {
                    break;
                }
            }
        }

        return false;  // Agar koi valid assignment nahi mila to false return karo
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int low = *max_element(jobs.begin(), jobs.end());  // Sabse badi job minimum workload hoga
        int high = accumulate(jobs.begin(), jobs.end(), 0);  // Maximum workload jab ek worker sab kuch kare
        int ans = high;  // Initial answer maximum workload assume kar ke chalenge

        // Binary search kar rahe hain minimum workload dhoondhne ke liye
        while (low < high) {
            int mid = low + (high - low) / 2;  // Mid workload ka limit decide kar rahe hain
            vector<int> workers(k, 0);  // Har worker ka workload 0 se shuru karo
            
            if (canDistribute(0, jobs, k, mid, workers)) {  
                ans = mid;   // Agar mid workload ke andar distribution ho sakta hai, to isse store kar lo
                high = mid ;  // Chhoti limit dhoondhne ke liye left side check karo
            } else {
                low = mid + 1;  // Agar nahi ho sakta, to limit badhao
            }
        }

        return ans;  // Minimum possible workload return karo
    }
};
