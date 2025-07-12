class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = firstPlayer;  // P1 ki position
        int right = secondPlayer; // P2 ki position

        // Agar P1 aur P2 opposite ends pe face kar rahe hain
        if(left == n - right + 1) {
            return {1, 1}; // Wo first round mein hi ladenge
        }

        // Ensure karo ki left < right (aur dono left side ke ho ya opposite ho)
        if(left > n - right + 1) {
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp;
        }

        int minRound  = n; // minimum round initialize kiya maximum possible se
        int maxRound  = 1; // maximum round initialize kiya minimum se
        int nextRoundPlayersCount = (n + 1) / 2; // agle round mein kitne players bache rahenge

        if(right <= nextRoundPlayersCount) {
            // ✅ Case-1: Dono players same side pe hain

            int countLeft = left - 1;         // left side pe kitne players hain
            int midCount  = right - left - 1; // dono ke beech mein kitne players hain

            // Har possible survivorsLeft aur survivorsMid combination ke liye
            for(int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for(int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft + 1; // P1 ki new position
                    int pos2 = pos1 + survivorsMid + 1; // P2 ki new position
                    vector<int> tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2);

                    // minimum aur maximum round update karo
                    minRound = min(minRound, tempResult[0] + 1);
                    maxRound = max(maxRound, tempResult[1] + 1);
                }
            }
        } else {
            // ✅ Case-2: Dono opposite ends pe hain

            int fightsRight = n - right + 1;  // Right side se fights count
            int countLeft = left - 1;         // Left side ke players
            int midCount = fightsRight - left - 1; // beech ke players jo kisi se nahi lad rahe
            int remainMidCount = right - fightsRight - 1; // middle mein bach gaye players

            for(int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for(int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft + 1; // P1 ki new position
                    // P2 ki new position: left survivors + mid survivors + half of remaining mid + 1
                    int pos2 = pos1 + survivorsMid + (remainMidCount + 1) / 2 + 1;

                    vector<int> tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2);

                    // minimum aur maximum round update karo
                    minRound = min(minRound, tempResult[0] + 1);
                    maxRound = max(maxRound, tempResult[1] + 1);
                }
            }
        }

        return {minRound, maxRound};
    }
};
