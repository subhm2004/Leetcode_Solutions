class Solution {
public:
    bool digitCount(string num) {
        vector<int> freq(10, 0); // Har digit (0-9) ki frequency store karne ke liye array

        // Har digit ko count karo jo string mein aayi hai
        for (char ch : num) {
            freq[ch - '0']++; // Character ko digit mein convert karke uski count badhao
        }

        // Ab check karo ki har position pe jo digit likhi hai, wohi us digit ki count hai ya nahi
        for (int i = 0; i < num.size(); i++) {
            int expectedCount = num[i] - '0'; // Yeh digit batati hai ki i waali digit kitni baar aani chahiye
            if (freq[i] != expectedCount) // Agar actual count match nahi karta
                return false; // Toh false return karo
        }

        return true; // Sab kuch match kiya toh true return karo
    }
};
