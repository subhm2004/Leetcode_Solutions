class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans;
        int P[1005];  // Permutation store karne ke liye (kyunki m ≤ 1000 diya hai)

        // Step 1: permutation P ko initialize karo [1, 2, 3, ..., m]
        for (int i = 0; i < m; i++) {
            P[i] = i + 1;
        }

        // Step 2: har query process karo
        for (int q : queries) {
            int pos = -1;

            // (a) Linear search karke pata karo ki q ka index kya hai
            for (int j = 0; j < m; j++) {
                if (P[j] == q) {
                    pos = j;
                    break;
                }
            }

            // (b) Ye index answer me store karo
            ans.push_back(pos);

            // (c) ab q ko front (index 0) pe le aao
            //     iske liye uske pehle wale sab elements ko 1 step right shift karna hoga
            int temp = P[pos];  // jis element ko front lana hai use store kar lo
            for (int j = pos; j > 0; j--) {
                P[j] = P[j - 1];  // har element ek step right shift ho jayega
            }
            P[0] = temp;  // aur finally q ko front pe rakh do
        }

        return ans;  // saare queries ka result return kar do
    }
};
