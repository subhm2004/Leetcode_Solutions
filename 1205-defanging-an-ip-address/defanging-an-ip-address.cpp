class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for (char ch : address) {
            if (ch == '.') {
                ans += "[.]";  // Agar dot mila to uski jagah [.] add karo
            } else {
                ans += ch;     // Nahi to normal character add karo
            }
        }
        return ans;
    }
};
