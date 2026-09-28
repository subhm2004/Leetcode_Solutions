class Solution {
public:
    int maxDepth(string s) {
        int result = 0;

        stack<char> st;
        
        for (char& ch : s) {
            
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                st.pop();
            }
            
            result = max(result, (int)st.size()); // size_t deta h to int me convert kr do 
        }
        
        return result;
    }
};