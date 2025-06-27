class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;  // Stack use karke expression process karenge.

        for (char c : expression) {
            if (c == ')') {  
                // Jab closing parenthesis ')' milega, toh sub-expression ko process karenge.
                bool hasTrue = false, hasFalse = false;

                // 't' ya 'f' ko pop karte rahenge jab tak ek operator na mil jaye.
                while (stk.top() == 't' || stk.top() == 'f') {
                    if (stk.top() == 't') hasTrue = true;
                    if (stk.top() == 'f') hasFalse = true;
                    stk.pop();
                }

                // Operator ('!', '&', ya '|') ko pop karenge.
                char op = stk.top(); 
                stk.pop();

                // Operator ke hisaab se sub-expression ko evaluate karenge.
                char ans;
                if (op == '!') 
                    ans = hasFalse ? 't' : 'f';  // NOT: '!' value ko flip kar deta hai.
                else if (op == '&') 
                    ans = hasFalse ? 'f' : 't';  // AND: '&' tabhi true hoga jab koi 'f' na ho.
                else  // '|'
                    ans = hasTrue ? 't' : 'f';  // OR: '|' tabhi true hoga agar koi 't' ho.

                // ans ko wapas stack mein daalenge.
                stk.push(ans);
            } 
            else if (c != ',' && c != '(') {
                // Sare relevant characters (operators aur 't'/'f') ko stack mein daalenge.
                stk.push(c);
            }
        }

        // Final ans stack ke top pe hoga.
        return stk.top() == 't';
    }
};
