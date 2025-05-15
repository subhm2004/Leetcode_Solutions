class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();     // total number of houses
        int maxDist = 0;           // max distance ko store karne ke liye variable

        // Case 1: Pehle house (index 0) ko last tak check karo 
        // aur dekho kaunsa aakhri house hai jo different color ka hai
        for (int i = n - 1; i >= 0; --i) {
            if (colors[i] != colors[0]) {
                maxDist = i - 0;   // distance calculate karo aur store karo
                break;             // jaise hi mil gaya, loop se bahar niklo
            }
        }

        // Case 2: Last house (index n-1) ko start se check karo 
        // aur dekho kaunsa pehla house hai jo different color ka hai
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                maxDist = max(maxDist, n - 1 - i);  // max distance update karo
                break;                              // jaise hi mil gaya, loop se bahar niklo
            }
        }

        return maxDist;  // final answer return karo
    }
};
