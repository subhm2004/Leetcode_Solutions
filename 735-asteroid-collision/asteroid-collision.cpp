class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[i] < 0 && st.top() > 0) {
                int sum = arr[i] + st.top();

                if (sum < 0) { // current jo aya tha wo bada tha to stack ke andar wala hat gya top se
                    st.pop();
                } else if (sum > 0) { // current jo tha wo chota tha 
                    arr[i] = 0;
                    break;
                }
                // sum == 0 dono barabar the 
                else {
                    st.pop();
                    arr[i] = 0;
                    break;
                }
            }
            if (arr[i] != 0)
                st.push(arr[i]);
        }
        int st_size = st.size();
        vector<int> ans(st_size, 0);
        for (int i = 0; i < st_size; i++) {
            ans[i] = st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};