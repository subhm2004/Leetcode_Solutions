class Solution {
public:

    long solveRE(int i, vector<vector<int>>& questions) {
        if (i >= questions.size()) return 0; // Base case: Agar index out of bounds ho gaya toh 0 return karo

        int points = questions[i][0];  // Is question ko solve karne pe milne wale points
        int brainpower = questions[i][1];  // Is question ko solve karne ke baad kitne questions skip karne hain
        int nextIndex = i + brainpower + 1;  // Next valid index jaha se solve kar sakte hain

        // Do choices hain: ya toh is question ko solve karein ya skip karein
        long include = points + solveRE(nextIndex, questions); // Agar solve karte hain toh points add karo aur nextIndex se solve karo
        long exclude = solveRE(i + 1, questions); // Agar skip karte hain toh next question pe chale jao

        return max(include, exclude); // Dono cases ka maximum return karo
    }

    long solveME(int i, vector<vector<int>>& questions, vector<long>& dp) {
        if (i >= questions.size()) return 0; 
        if (dp[i] != -1) return dp[i]; 

        int points = questions[i][0];  
        int brainpower = questions[i][1];  
        int nextIndex = i + brainpower + 1;  

        long include = points + solveME(nextIndex, questions, dp);
        long exclude = solveME(i + 1, questions, dp);

        return dp[i] = max(include, exclude); 
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n, -1); 
        return solveME(0, questions, dp); 
    }
};
