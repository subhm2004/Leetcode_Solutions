class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        
        long long score_1 = 0;
        long long score_2 = 0;

        bool first_player_active = true;   // initially player 1 active

        for (int i = 0; i < nums.size(); i++) {

            // Rule 1: odd value -> swap
            if (nums[i] % 2 == 1)
                first_player_active = !first_player_active;

            // Rule 2: every 6th game (index 5,11,17...)
            if ((i + 1) % 6 == 0)
                first_player_active = !first_player_active;

            // Active player ko points milte hai
            if (first_player_active)
                score_1 += nums[i];
            else
                score_2 += nums[i];
        }

        return score_1 - score_2;
    }
};