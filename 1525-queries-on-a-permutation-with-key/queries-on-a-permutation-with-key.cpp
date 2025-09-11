class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans;
        int P[1005];  // kyunki m <= 1000

        // permutation initialize karo
        for (int i = 0; i < m; i++) {
            P[i] = i + 1;
        }

        // har query process karo
        for (int q : queries) {
            int pos = -1;

            // manually search karo index
            for (int j = 0; j < m; j++) {
                if (P[j] == q) {
                    pos = j;
                    break;
                }
            }

            ans.push_back(pos);

            // element ko front pe le aao (shift)
            int temp = P[pos];
            for (int j = pos; j > 0; j--) {
                P[j] = P[j - 1];
            }
            P[0] = temp;
        }

        return ans;
    }
};
