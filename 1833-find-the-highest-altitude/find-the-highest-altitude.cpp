class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0, altitude = 0;
        for (int change : gain) {
            altitude += change;
            highest = max(highest, altitude);
        }
        return highest;
    }
};