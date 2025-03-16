class Solution {
public:
    // yeh function check karta hai ki given time me required cars repair ho
    // sakti hai ya nahi

    bool canFixEnoughCars(const vector<int>& ranks, int cars, long time) {
        long totalCars = 0;
        for (int rank : ranks) {
            totalCars += sqrt(time / rank); // har mechanic ka max possible
                                            // repaired cars count kar rahe hain
            if (totalCars >= cars)
                return true; // agar required cars repair ho gayi toh aage check
                             // karne ki zaroorat nahi
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long left = 0;
        long right = *max_element(ranks.begin(), ranks.end()) * (long)cars * cars;

        while (left < right) {
            long mid = (left + right) >> 1;
            if (canFixEnoughCars(ranks, cars, mid))
                right = mid; // agar cars repair ho sakti hai toh aur kam time
                             // check karenge
            else
                left = mid + 1; // agar nahi ho sakti toh time badhana padega
        }

        return left; 
    }
};
