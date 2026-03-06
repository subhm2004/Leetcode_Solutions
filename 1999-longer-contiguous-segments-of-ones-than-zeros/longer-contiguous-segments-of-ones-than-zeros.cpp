class Solution {
public:

    int longest_segment(string &s, char ch){

        int count = 0;
        int max_len = 0;

        for(char c : s){

            if(c == ch){
                count++;
                max_len = max(max_len, count);
            }
            else{
                count = 0;
            }
        }

        return max_len;
    }

    bool checkZeroOnes(string s) {

        int longest1 = longest_segment(s,'1');
        int longest0 = longest_segment(s,'0');

        return longest1 > longest0;
    }
};