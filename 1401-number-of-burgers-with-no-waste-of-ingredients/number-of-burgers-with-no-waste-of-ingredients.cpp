class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2) {
            return {};
        }

        int jumbo = tomatoSlices / 2 - cheeseSlices;
        int small = cheeseSlices - jumbo;

        if (jumbo < 0 || small < 0) {
            return {};
        }

        return {jumbo, small};
    }
};