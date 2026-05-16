class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // tomatoSlices odd nhi ho skti h 
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