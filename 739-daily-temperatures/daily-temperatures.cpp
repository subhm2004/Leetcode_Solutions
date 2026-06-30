class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // Total number of days
        int n = temperatures.size();

        // Answer array.
        // By default sabki value 0 rakhi hai,
        // kyunki agar kisi din future me warmer temperature na mile
        // to answer wahi 0 rahega.
        vector<int> ans(n, 0);

        // Stack me hum temperatures nahi,
        // unke INDEX store karenge.
        // Stack me unhi days ke index honge
        // jinka answer abhi tak nahi mila hai.
        stack<int> st;

        // Left se Right traverse karenge
        for (int i = 0; i < n; i++) {

            // Agar stack empty nahi hai aur
            // current temperature stack ke top wale day se zyada hai,
            // iska matlab current day us top wale day ka
            // "Next Warmer Day" ban gaya.
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {

                // Stack ke top wale day ka index nikal lo
                int index = st.top();

                // Ab iska answer mil gaya,
                // isliye ise stack se hata do.
                st.pop();

                // Current day (i) aur us purane day (index)
                // ke beech ka difference hi required answer hai.
                ans[index] = i - index;
            }

            // Current day ka answer abhi nahi mila hai,
            // isliye ise stack me store kar do.
            // Ho sakta hai future me koi aur warmer day aaye.
            st.push(i);
        }

        // Jo indices stack me bach gaye,
        // unka koi warmer temperature future me nahi mila.
        // Unka answer already 0 hai,
        // isliye unke liye kuch karne ki zarurat nahi.

        return ans;
    }
};