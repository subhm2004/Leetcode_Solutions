class Solution {
public:
    int get_str_value(string s) {
        int num = 0;
        for (char c : s) {
            num = num * 10 + (c - 'a');
        }
        return num;
    }
    /*
        s = "acb"
        pehla char 'a' → 0 → num = 0

        dusra char 'c' → 2 → num = 0*10 + 2 = 2

        teesra char 'b' → 1 → num = 2*10 + 1 = 21

    */
    int get_value(string s) {
        string num = "";
        for (char c : s)
            num += to_string(c - 'a');
        return stoi(num);
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return get_str_value(firstWord) + get_str_value(secondWord) == get_str_value(targetWord);
    }
};
