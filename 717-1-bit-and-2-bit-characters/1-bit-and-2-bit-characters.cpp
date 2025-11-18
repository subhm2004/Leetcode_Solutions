class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();

        // last index pe 0 hamesha hota hai (ques me diya hai)
        while (i < n - 1) {
            if (bits[i] == 1) {
                // 2-bit character hai → skip next bit
                i = i+2;
            } else {
                // 1-bit character hai
                i = i+1;
            }
        }

        // agar loop end hoke last 0 pe aaya → true
        return i == n - 1;
    }
};
