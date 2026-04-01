class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];

            //opening bracket
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                //closing bracket - ch
                if(!st.empty()) {
                    char top_ch = st.top();
                    if(ch == ')' && top_ch =='(') {
                        //matching brackets
                        st.pop();
                    }
                    else if(ch == '}' && top_ch =='{') {
                        //matching brackets
                        st.pop();
                    }
                    else if(ch == ']' && top_ch =='[') {
                        //matching brackets
                        st.pop();
                    }
                    else {
                        //brackets not matching
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }

        if(st.empty()) {
            //valid 
            return true;
        }
        else {
            return false;
        }
        
    }
};