class Solution {
public:
    bool is_Possible(const vector<int>& bloomDay, int m, int k, int days) {
        int bouquet_Count = 0;
        int current_Bouquet_Count = 0;

        for (int day : bloomDay) {
            if (day <= days) {
                current_Bouquet_Count++;
                if (current_Bouquet_Count == k) {
                    bouquet_Count++;
                    current_Bouquet_Count = 0;
                }
            } else {
                current_Bouquet_Count = 0;
            }

            if (bouquet_Count >= m) {
                return true;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL* bloomDay.size() < 1LL* m * k) {
            return -1;
        }

        // int left = 1;  
        // int right = 1e9;  
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = (left + right) >> 1;
            if (is_Possible(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
