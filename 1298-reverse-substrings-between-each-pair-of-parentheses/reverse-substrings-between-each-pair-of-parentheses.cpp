class Solution {
public:
    string reverseParentheses(string s) {
    stack<char> stk;
    
    for (char& c : s) {
        if (c == ')') {
            string t;
            while (stk.top() != '(') {
                t.push_back(stk.top());
                stk.pop();
            }
            stk.pop(); // remove the '(' from the stack
            for (char& ch : t) {
                stk.push(ch);
            }
        } else {
            stk.push(c);
        }
    }
    
    string result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
};