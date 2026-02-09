class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;    

        for (int x : nums) {

            st.push_back(x);

            // merge karte hro jab tak last ke elemts equal hai 
            while (st.size() >= 2) {
                int n = st.size();

                if (st[n - 1] == st[n - 2]) {
                    long long val = st[n - 1] + st[n - 2];
                    st.pop_back();
                    st.pop_back();
                    st.push_back(val);
                } else {
                    break;
                }
            }
        }

        vector<long long> ans;
        for (auto v : st) ans.push_back(v);
        return ans;
    }
};