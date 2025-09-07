class Solution {
public:
    int minOperations(string s) {
        int maxi = INT_MIN;
        for(char ch : s){
            int steps = (26-(ch-'a'))%26;
            maxi = max(maxi,steps);
        }
        return maxi;
    }
};