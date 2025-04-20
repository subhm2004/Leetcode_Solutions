class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;  

        // count[i] ka matlab: abhi current group mein i answer wale rabbits kitne aur aa sakte hain
        vector<int> count(1001, 0);

        // Har rabbit ka answer check karte hain
        for (int i = 0; i < answers.size(); ++i) {
            int answer = answers[i];         // Current rabbit ka answer
            int groupSize = answer + 1;      // Uske group mein total itne rabbits ho sakte hain

            // Agar current group full ho gaya ya koi group bana hi nahi
            if (count[answer] == 0) {
                ans += groupSize;            // Naya group banate hain
                count[answer] = answer;      // Is group mein ab aur itne rabbits aa sakte hain
            } else {
                count[answer]--;             // Ek rabbit aur add kar diya group mein
            }
        }

        return ans;  
    }
};
