class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        vector<pair<int, int>> arr; //{positions , index}

        for (int i = 0; i < n; i++) {
            arr.push_back({positions[i], i});
        }
        sort(arr.begin(), arr.end());

        stack<int> st; // stores index
        for (auto val : arr) {
            int i = val.second;
            while (!st.empty() && directions[st.top()] == 'R' && directions[i] == 'L') {
                int j = st.top();
                // stack wala robot strong hai 
                
                if (healths[j] > healths[i]) {
                    healths[j]--;
                    healths[i] = 0;
                    break;
                } else if (healths[j] < healths[i]) {
                    // stack wala robot kamzor hai to baad m bhi check hoga koi or koi bhi kamzor to nhi stack me
                    st.pop();
                    healths[i]--;
                    healths[j] = 0;
                } else {
                    // dono robots ki health same hai to dono ko hata denge
                    st.pop();
                    healths[i] = 0;
                    healths[j] = 0;
                    break;
                }
            }
            if(healths[i] > 0){
                st.push(i);
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            if(healths[i] > 0) ans.push_back(healths[i]);
        }
        return ans;
    }
};