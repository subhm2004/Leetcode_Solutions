class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        
        for (int x : nums) {
            if (st.count(x)) {
                return x;
            }
            st.insert(x);
        }
        
        return -1; // guaranteed case me yahan kabhi nahi aayega
    }
};