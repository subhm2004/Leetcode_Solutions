class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int requiredHours(vector<int>& piles, int speed) {
        int totalHours = 0;
        for (int pile : piles) {
            totalHours +=
                (pile + speed - 1) / speed; // Equivalent to ceil(pile / speed)
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = (low + high) / 2;
            if (requiredHours(piles, mid) <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};