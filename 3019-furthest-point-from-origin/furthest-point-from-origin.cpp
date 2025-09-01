class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans1 = 0;
        int ans2 = 0;
        int temp = 0;
        
        for(auto i: moves) {
            if(i == 'L' ) ans1++;
            if(i == 'R') ans2++;
            if(i == '_') temp++;
        }
        
        return abs(ans1-ans2) + temp;
    }
};

