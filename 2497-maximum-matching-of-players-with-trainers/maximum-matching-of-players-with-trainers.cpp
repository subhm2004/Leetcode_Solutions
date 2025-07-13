class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0;
        int matches = 0;

        while (i < players.size() && j < trainers.size()) {
            if (trainers[j] >= players[i]) {
                // Match found
                matches++;
                i++;
            }
            // Move to next trainer in any case
            j++;
        }
        return matches;
    }
};
