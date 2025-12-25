class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;  
        int decrement = 0; // Yeh track karega ki har happiness value se kitna decrease karna hai

        // descending order mein sort karte hain taaki sabse badi values pehle aayein
        sort(happiness.begin(), happiness.end(), greater<>());

        // Ab pehle k elements ko process karte hain
        for (int i = 0; i < k; ++i) {
            // Har element se decrement ko subtract karte hain, lekin value 0 se kam nahi hona chahiye
            ans += max(0, happiness[i] - decrement);
            
            // Agle iteration ke liye decrement ko increase karte hain
            decrement++;
        }

        return ans;  
    }
};
