class Solution {
public:
    /* ── check: kya pehle `k` indices hata ke bhi p subsequence rehta hai? ──
       1) removed[] me mark karo kaunse index hatane hain
       2) s pe chalo, marked skip karo, baaki se p match karne ki koshish karo
       */
    bool is_possible(int k, string& s, string& p, vector<int>& removable) {

        int n = s.size(), m = p.size();

        vector<bool> removed(n, false);
        for (int i = 0; i < k; i++)
            removed[removable[i]] = true;

        int j = 0;                          // p ka pointer
        for (int i = 0; i < n && j < m; i++) {
            if (removed[i]) continue;       // ye char hata diya gaya
            if (s[i] == p[j]) j++;          // match mila, p me aage badho
        }

        return j == m;                      // poora p match ho gaya?
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {


        int low = 0;
        int high = removable.size();
        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (is_possible(mid, s, p, removable)) {
                ans = mid;          
                low = mid + 1; 
            } else {
                high = mid - 1;     
            }
        }

        return ans;
    }
};