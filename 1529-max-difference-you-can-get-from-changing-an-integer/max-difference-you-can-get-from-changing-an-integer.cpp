class Solution {
public:
    int maxDiff(int num) {
        string high = to_string(num); // For max number
        string low = high;            // For min number

        // Step 1: Make the largest number possible by replacing a digit with 9
        for (char ch : high) {
            if (ch != '9') {
                // Replace all occurrences of the first non-9 digit with '9'
                for (char &c : high) {
                    if (c == ch) c = '9';
                }
                break;
            }
        }

        // Step 2: Make the smallest number possible by replacing a digit
        if (low[0] != '1') {
            // Replace first digit (if not already '1') with '1'
            char ch = low[0];
            for (char &c : low) {
                if (c == ch) c = '1';
            }
        } else {
            // Otherwise, replace first digit (not '0' or first digit itself) with '0'
            for (int i = 1; i < low.size(); i++) {
                if (low[i] != '0' && low[i] != low[0]) {
                    char ch = low[i];
                    for (char &c : low) {
                        if (c == ch) c = '0';
                    }
                    break;
                }
            }
        }

        return stoi(high) - stoi(low);
    }
};
