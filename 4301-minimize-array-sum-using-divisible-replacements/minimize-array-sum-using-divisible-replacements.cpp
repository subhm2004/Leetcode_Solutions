class Solution {
public:
    long long minArraySum(vector<int>& nums) {

        vector<bool> is_present(1e5 + 1, false);

        // jo jo number array me present hai unhe true mark kr dete hai 
        for (int x : nums) {
            is_present[x] = true;
        }

        long long sum = 0;

        for (int x : nums) {

            int smallest = x;

            //  smallest divisor dhoond te hai jo array me present hai present number ka 
            for (int d = 1; d * d <= x; d++) {

                if (x % d == 0) {

                    // divisor d
                    if (is_present[d]) {
                        smallest = min(smallest, d);
                    }

                    // second divisor
                    int other_divisor = x / d;

                    if (is_present[other_divisor]) {
                        smallest = min(smallest, other_divisor);
                    }
                }
            }

            sum += smallest;
        }

        return sum;
    }
};