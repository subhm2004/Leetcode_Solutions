class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int already_satisfied = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                already_satisfied += customers[i];
            }
        }

        int extra_satisfied = 0;
        int max_extra = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 1) {
                extra_satisfied += customers[i];
            }

            if (i >= minutes) {
                if (grumpy[i - minutes] == 1) {
                    extra_satisfied -= customers[i - minutes];
                }
            }

            max_extra = max(max_extra, extra_satisfied);
        }

        return already_satisfied + max_extra;
    }
};
