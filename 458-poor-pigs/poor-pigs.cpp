class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests_trials = minutesToTest / minutesToDie;
        int pigs = 0;
        while (pow(tests_trials + 1, pigs) < buckets) {
            pigs++;
        }
        return pigs;
    }
};
