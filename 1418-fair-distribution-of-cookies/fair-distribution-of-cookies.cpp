class Solution {
public:
    // Ye function check karta hai ki given limit ke andar cookies ko distribute kiya ja sakta hai ya nahi
    bool canDistribute(int idx, const vector<int>& cookies, int k, int limit, vector<int>& children) {
        if (idx == cookies.size()) {
            return true;  // Agar saari cookies assign ho gayi, to valid distribution mil gaya
        }

        // Har child ko ek ek cookie assign karne ki koshish karte hain
        for (int i = 0; i < k; ++i) {
            if (children[i] + cookies[idx] <= limit) {  // Agar current child yeh cookie le sakta hai
                children[i] += cookies[idx];  // Cookie assign kar do

                if (canDistribute(idx + 1, cookies, k, limit, children)) {  
                    return true;  // Agar aage ka distribution possible hai to return true
                }

                children[i] -= cookies[idx];  // Backtrack: Cookie hata do

                // Pruning: Agar child pehle empty tha aur yeh cookie nahi le saka,
                // to aage wale bhi nahi le sakenge, isliye yahin break kar do
                if (children[i] == 0) {
                    break;
                }
            }
        }

        return false;  // Agar koi valid assignment nahi mila to false return karo
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int low = *max_element(cookies.begin(), cookies.end());  // Sabse badi cookie minimum unfairness hogi
        int high = accumulate(cookies.begin(), cookies.end(), 0);  // Maximum unfairness jab ek child sab kuch le le
        int ans = high;  // Initial answer maximum unfairness assume kar ke chalenge

        // Binary search kar rahe hain minimum unfairness dhoondhne ke liye
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Mid unfairness ka limit decide kar rahe hain
            vector<int> children(k, 0);  // Har child ka cookie count 0 se shuru karo
            
            if (canDistribute(0, cookies, k, mid, children)) {  
                ans = mid;   // Agar mid unfairness ke andar distribution ho sakta hai, to isse store kar lo
                high = mid - 1;  // Chhoti limit dhoondhne ke liye left side check karo
            } else {
                low = mid + 1;  // Agar nahi ho sakta, to limit badhao
            }
        }

        return ans;  // Minimum possible unfairness return karo
    }
};
