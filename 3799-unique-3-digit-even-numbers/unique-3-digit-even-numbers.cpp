class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;
        int n = digits.size();
        
        // Pehli digit kabhi bhi 0 nahi ho sakti, isliye pehle check karein
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue; // Leading zero allowed nahi hai
            
            for (int j = 0; j < n; j++) {
                if (i == j) continue; // Same index ka use na ho
                
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue; // Ek hi digit do baar na aaye
                    if (digits[k] % 2 != 0) continue; // Last digit even honi chahiye

                    // 3-digit ka number banao
                    int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                    uniqueNumbers.insert(number); // Unique numbers ko store karo
                }
            }
        }
        return uniqueNumbers.size(); // Total distinct 3-digit even numbers ka count return karo
    }
};
