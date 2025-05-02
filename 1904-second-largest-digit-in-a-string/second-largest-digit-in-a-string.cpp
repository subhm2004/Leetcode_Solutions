class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        
        for (char c : s) {
            if (isdigit(c)) {
                int digit = c - '0';
                
                if (digit > first) {
                    second = first;
                    first = digit;
                } else if (digit < first && digit > second) {
                    second = digit;
                }
            }
        }
        
        return second;
    }
};
