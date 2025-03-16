typedef long long ll;
class Solution {
public:
    // yeh function check karta hai ki given time me required cars repair ho
    // sakti hai ya nahi

    bool is_Possible(vector<int>& ranks, ll cars, ll time) {
        ll totalCars = 0;
        for (int rank : ranks) {
            totalCars += sqrt(time / rank); // har mechanic ka max possible
                                            // repaired cars count kar rahe hain
            if (totalCars >= cars)
                return true; // agar required cars repair ho gayi toh aage check
                             // karne ki zaroorat nahi
        }
        return false;
    }

   ll repairCars(vector<int>& ranks, int cars) {
        ll left = 1;
        ll right = *max_element(ranks.begin(), ranks.end()) * (1LL * cars * cars);

        while (left < right) {
            ll mid = (left + right) >> 1;
            if (is_Possible(ranks, cars, mid))
                right = mid; // agar cars repair ho sakti hai toh aur kam time
                             // check karenge
            else
                left = mid + 1; // agar nahi ho sakti toh time badhana padega
        }

        return left; 
    }
};
