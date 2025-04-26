class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();  
        vector<int> div(n, 0);  
        long long prefix = 0;  // current prefix number ko store karne ke liye prefix variable

        for (int i = 0; i < n; i++) {
            // Har digit ko prefix me add kar rahe hain aur modulo m le rahe hain
            prefix = (prefix * 10 + (word[i] - '0')) % m;  // current digit ko prefix me add kar rahe hain

            // Ab check kar rahe hain ki prefix m se divisible hai ya nahi
            if (prefix == 0) {
                div[i] = 1;  // Agar divisible hai, toh div[i] ko 1 set karo
            } else {
                div[i] = 0;  // Agar divisible nahi hai, toh div[i] ko 0 set karo
            }
        }

        return div;  
    }
};
