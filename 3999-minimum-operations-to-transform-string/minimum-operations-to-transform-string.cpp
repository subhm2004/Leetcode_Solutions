class Solution {
public:
    int minOperations(string s) {
        int max_steps = 0;
        for (char ch : s) {
            int steps = (26 - (ch - 'a')) % 26; 
            max_steps = max(max_steps, steps);
        }
        return max_steps;
    }
};
