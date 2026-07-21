class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Step 1: Original string mein total '1's count karo
        // (ye base answer hai — trade se sirf gain add hoga)
        int totalOnes = count(s.begin(), s.end(), '1');

        // Step 2: Augmented string t = '1' + s + '1' banao
        // Note: actually string banane ki zaroorat nahi,
        // hume sirf zero-runs chahiye — aur augmentation se
        // zero-runs waise hi nahi badalte (bas boundary pe '1' lagta hai).
        // Lekin augmentation IMPORTANT hai kyunki iske wajah se
        // s ke edge wale zero-blocks bhi "1 se surrounded" ban jaate hain
        // agar unke aage/piche koi 1-run ho.
        string t = "1" + s + "1";

        // Step 3: t ke saare consecutive zero-runs ki lengths nikalo
        // t mein har zero-run ke dono side '1' hota hai (by construction),
        // isliye koi bhi DO ADJACENT zero-runs ke beech exactly ek 1-run hai.
        vector<int> zeroRuns;
        int i = 0, m = t.size();
        while (i < m) {
            if (t[i] == '0') {
                int j = i;
                while (j < m && t[j] == '0') j++;  // pura zero block consume karo
                zeroRuns.push_back(j - i);          // run ki length store
                i = j;
            } else {
                i++;  // '1' skip karo
            }
        }

        // Step 4: Trade tabhi possible hai jab kam se kam 2 zero-runs ho
        // (kyunki beech ka 1-block hi "surrounded by 0s" wala block hai).
        // Best trade = adjacent zero-runs ka max pair-sum.
        //
        // Dry run (s = "1000100", t = "110001001"):
        //   zeroRuns = [3, 2]
        //   beech ka "1" delete → phir pura "00000" ko 1 bana do
        //   gain = 3 + 2 = 5, answer = 2 + 5 = 7 ✓
        int bestGain = 0;
        for (int k = 0; k + 1 < (int)zeroRuns.size(); k++) {
            bestGain = max(bestGain, zeroRuns[k] + zeroRuns[k + 1]);
        }

        // Step 5: Final answer
        // Agar 2 zero-runs nahi mile → bestGain = 0 → no trade case
        return totalOnes + bestGain;
    }
};