class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(x - z);  // Distance of Person 1 from Person 3
        int dist2 = abs(y - z);  // Distance of Person 2 from Person 3

        if (dist1 < dist2) return 1;  // Person 1 is closer
        if (dist2 < dist1) return 2;  // Person 2 is closer
        return 0;                     // Both reach at the same time
    }
};
