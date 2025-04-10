class Solution {
public:
    // Yeh function count karta hai kitne numbers [0...str] tak valid hain 
    // jinke last digits 'suffix' ke equal hain aur har digit limit se chhoti ya barabar hai.
    long long solve(const string& str, const string& suffix, int limit) {
        // Agar number ki length suffix se chhoti hai, toh suffix match ho hi nahi sakta
        if (str.length() < suffix.length())
            return 0;

        // Agar length equal hai, toh directly compare karo suffix se
        if (str.length() == suffix.length())
            return str >= suffix ? 1 : 0;

        long long count = 0;
        // Last ke characters (suffix length ke) nikalo
        string trailing = str.substr(str.length() - suffix.length());
        // Prefix ki length nikal lo (jo suffix ke aage waale digits hain)
        int prefixLength = str.length() - suffix.length();

        // Har prefix digit pe loop
        for (int i = 0; i < prefixLength; ++i) {
            int digit = str[i] - '0'; // current digit

            if (limit < digit) {
                // Agar digit limit se zyada hai, toh uske aage ke saare combinations valid honge
                count += pow(limit + 1, prefixLength - i);
                return count;
            } else {
                // Agar digit limit ke andar hai, toh us digit ke base pe combinations add karo
                count += digit * pow(limit + 1, prefixLength - i - 1);
            }
        }

        // Agar suffix part bhi valid hai (greater ya equal hai suffix se), toh ek aur add karo
        if (trailing >= suffix)
            count++;

        return count;
    }

    // Yeh function start se finish tak ke range mein valid numbers count karta hai
    long long numberOfPowerfulInt(long long start, long long finish, int limit, const string& s) {
        string startStr  = to_string(start - 1); // start se pehle tak ke numbers ka count
        string finishStr = to_string(finish);    // finish tak ke numbers ka count
        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};
