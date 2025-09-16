class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; // popped pointer

        for (int x : pushed) {
            st.push(x); // push element
            // check if top matches with popped
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return st.empty(); // agar sab match ho gaya
    }
};