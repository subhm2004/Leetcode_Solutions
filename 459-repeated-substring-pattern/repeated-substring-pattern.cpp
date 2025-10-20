class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // Step 1: Original string ko apne aap ke saath concatenate karte hain
        // Agar s = "abab", toh ss = "abab" + "abab" = "abababab"
        string ss = s + s;

        // Step 2: Pehla aur last character remove karte hain
        // Ye step zaruri hai, warna original string khud bhi match ho jayegi
        // Example: s = "abab", ss = "abababab"
        // ss.substr(1, ss.length() - 2) = "bababab"
        // Is trimmed string me find karenge original string s ko
        // Agar s kisi repeated substring pattern ke wajah se present hai, toh match hoga
        // Agar s repeat nahi hota, toh match nahi hoga
        string trimmed = ss.substr(1, ss.length() - 2);

        // Step 3: Check karte hain agar original string s, trimmed string me exist karta hai
        // find() function returns index of first occurrence or string::npos if not found
        // Agar exist karta hai → repeated substring pattern exist karta hai → return true
        // Agar exist nahi karta → repeated substring pattern nahi hai → return false
        return trimmed.find(s) != string::npos;
    }
};
