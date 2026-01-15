class Solution {
public:
    long long MOD = 1e9 + 7;

    int countOrders(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = (ans * i * (2 * i - 1)) % MOD;
        }
        return ans;
    }
};

    // (2*i - 1) = the number of the spaces where we can put pi (i-1 order place ho chuke hai to mtlb 2(i-1) places filled hai iska ltb ki Total spaces hai 2(i-1) + 1 = 2i -1)
    // ab jab 2i-1 spaces me se ek par hum ne pi ko rakh diya to ab bari aati hai di ko rakhen ki jisme se total spaces ab banete hai 2(i-1) + 2 = 2i spaces lekin in me se aadhe ese hone jo invalid hoge kyoki un me di aage hoga pi se to total valid postions hogi 2i/2 = i 

    // Here, i = number of valid positions for the delivery of that order after its pickup.

    
/*
        Explanation:

        Total orders = n
        Each order has a Pickup (Pi) and Delivery (Di)
        Total slots = 2*n (each order occupies 2 slots)

        Step-by-step for n = 3:
        ---------------------------------
        Order 1 (P1,D1):
        - Total slots = 6
        - Ways to choose 2 slots from 6 = 6C2 = 15
        - Delivery must come after Pickup → 1 valid arrangement per choice
        - Total ways for first order = 6C2 = 15

        Order 2 (P2,D2):
        - Remaining slots = 4
        - Ways to choose 2 slots from 4 = 4C2 = 6
        - Delivery must come after Pickup → 1 valid arrangement per choice
        - Total ways for second order = 4C2 = 6

        Order 3 (P3,D3):
        - Remaining slots = 2
        - Ways to choose 2 slots from 2 = 2C2 = 1
        - Delivery must come after Pickup → 1 valid arrangement
        - Total ways for third order = 2C2 = 1

        Total ways = 6C2 * 4C2 * 2C2 = 15 * 6 * 1 = 90

        Mathematical formula: ∏(i=1 to n) 2iC2 == ∏(i=1 to n) (2i * (2i-1))/2 == ∏(i=1 to n) i * (2i-1)
        - Generalized formula: countOrders(n) = ∏(i=1 to n) i * (2i-1)
        - i = number of ways to place Pickup Pi
        - (2i-1) = number of ways to place Delivery Di after Pickup
        - This formula is equivalent to multiplying all 2C2 values step by step
        - Finally, take modulo 10^9 + 7
        */