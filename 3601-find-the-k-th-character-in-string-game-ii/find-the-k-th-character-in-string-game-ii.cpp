class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1) return 'a';

        int n = operations.size();
        int opr_type;
        long long len = 1;
        long long new_k;

        for (int i = 0; i < n; i++) {
            len *= 2;
            if (len >= k) {
                opr_type = operations[i];
                new_k = k - len / 2;
                break;
            }
        }

        char ans = kthCharacter(new_k, operations);
        if (opr_type == 0) return ans;
        return ans == 'z' ? 'a' : ans + 1;
    }
};
