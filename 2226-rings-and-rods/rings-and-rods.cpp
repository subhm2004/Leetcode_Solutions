class Solution {
public:
    int countPoints(string rings) {
        // ek road p konsa color kitni baar aya hai 
        unordered_map<int, unordered_map<char, int>> rods; 

        for (int i = 0; i < rings.length(); i += 2) {
            char color = rings[i];
            int rod = rings[i + 1] - '0';
            rods[rod][color]++;
        }

        int count = 0;
        for (auto& [rod, colorMap] : rods) {
            if (colorMap.find('R') != colorMap.end() &&
                colorMap.find('G') != colorMap.end() &&
                colorMap.find('B') != colorMap.end()) {
                count++;
            }
        }

        return count;
    }
};
