class Solution {
public:
    int solveRE(vector<int>& nums, int i, bool isUp) {
        int maxLen = 0;

        // Har agle i ko check karo
        for (int next = i + 1; next < nums.size(); ++next) {

            // Agar current move upar ka chahiye (isUp == true)
            // aur next element bada hai, to valid move hai
            if (isUp && nums[next] > nums[i]) {
                // 1 move add karo aur aage ke result me dekho kya best hai
                maxLen = max(maxLen, 1 + solveRE(nums, next, !isUp));
            }

            // Agar current move neeche ka chahiye (isUp == false)
            // aur next element chhota hai, to valid move hai
            else if (!isUp &&   nums[i] > nums[next]) {
                // 1 move add karo aur aage ke result me dekho kya best hai
                maxLen = max(maxLen, 1 + solveRE(nums, next, !isUp));
            }
        }

        // Is i se start karke max wiggle length return karo
        return maxLen;
    }

    int solveME(vector<int>& nums, int i, bool isUp, vector<vector<int>>& dp) {
        if (dp[i][isUp] != -1)
            return dp[i][isUp];

        int maxLen = 0;

        for (int next = i + 1; next < nums.size(); ++next) {
            if (isUp && nums[next] > nums[i]) {
                maxLen = max(maxLen, 1 + solveME(nums, next, !isUp, dp));
            }
            else if (!isUp && nums[next] < nums[i]) {
                maxLen = max(maxLen, 1 + solveME(nums, next, !isUp, dp));
            }
        }

        return dp[i][isUp] = maxLen;
    }

    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        int up = solveME(nums, 0, true, dp);    // Pehla move upar ho
        int down = solveME(nums, 0, false, dp); // Pehla move neeche ho

        return max(up, down) + 1; // +1 to count the first element
    }
};
