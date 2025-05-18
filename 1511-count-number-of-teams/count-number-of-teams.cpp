class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for (int j = 1; j < n - 1; ++j) {
            int left_Smaller = 0, left_Greater = 0;
            int right_Smaller = 0, right_Greater = 0;

            // Count for left side
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) left_Smaller++;
                else if (rating[i] > rating[j]) left_Greater++;
            }

            // Count for right side
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] > rating[j]) right_Greater++;
                else if (rating[k] < rating[j]) right_Smaller++;
            }

            count += left_Smaller * right_Greater + left_Greater * right_Smaller;
        }

        return count;
    }
};
