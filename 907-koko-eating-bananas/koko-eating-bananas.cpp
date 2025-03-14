class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    // Ye function calculate karega ki given speed pe total kitne hours lagenge
    // sab piles ko khatam karne me
    int requiredHours(vector<int>& piles, int speed) {
        int totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + speed - 1) / speed; // Ye (pile/speed) ka ceil version hai
        }
        return totalHours;
    }

    // Ye function minimum speed dhoondhne ke liye binary search ka use karega
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = (low + high) >> 1; // Beech ka speed le rahe hain
            if (requiredHours(piles, mid) <= h) {
                high = mid; // Agar time limit ke andar hai to speed kam kar
                            // sakte hain
            } else {
                low = mid + 1; // Agar time zyada lag raha hai to speed badhani padegi
            }
        }
        return low; // Yahi minimum speed hai jo kaam karegi
    }
};
