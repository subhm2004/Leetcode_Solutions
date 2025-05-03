class Solution {
public:
    // Ye function check karta hai ki given number se sab domino match ho sakte hain ya nahi
    // Aur agar ho sakte hain toh minimum swaps kitne lagenge
    int count_Swaps(vector<int>& tops, vector<int>& bottoms, int value) {
        int n = tops.size();
        int swaps_Top = 0, swaps_Bottom = 0;

        for (int i = 0; i < n; ++i) {
            // Agar na top na bottom me target hai, toh possible hi nahi
            if (tops[i] != value && bottoms[i] != value) {
                return -1;
            }
            // Agar top me target nahi hai, toh bottom se swap karna padega
            if (tops[i] != value) {
                swaps_Top++;
            }
            // Agar bottom me target nahi hai, toh top se swap karna padega
            if (bottoms[i] != value) {
                swaps_Bottom++;
            }
        }

        // Dono me se minimum swaps return karo
        return min(swaps_Top, swaps_Bottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;

        // 1 se leke 6 tak ke numbers try karo (kyunki domino pe sirf 1-6 hote hain)
        for (int value = 1; value <= 6; ++value) {
            int swaps = count_Swaps(tops, bottoms, value);
            // Agar ye value se match possible hai toh ans update karo
            if (swaps != -1) {
                ans = min(ans, swaps);
            }
        }

        // Agar koi bhi value se match possible nahi tha toh -1 return karo
        return ans == INT_MAX ? -1 : ans;
    }
};
