class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int consumed = 0;

        while (numBottles >= numExchange) {
            consumed += numExchange;   // drink numExchange bottles
            numBottles -= numExchange; // they become empty

            numBottles += 1;           // exchange for 1 full
            numExchange++;             // cost increases
        }

        return consumed + numBottles;  
    }
};
