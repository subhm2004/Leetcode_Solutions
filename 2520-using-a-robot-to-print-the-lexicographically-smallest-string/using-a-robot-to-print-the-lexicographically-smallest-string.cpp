class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        // Har index ke right me jo chhoti char hai usse store karte hain
        vector<char> minRight(n);
        minRight[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minRight[i] = min(s[i], minRight[i + 1]);
        }

        stack<char> t;
        string ans;

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);

            // Agar aage character bacha hai, tabhi minRight[i+1] access karo
            while (!t.empty() && (i + 1 == n || t.top() <= minRight[i + 1])) {
                ans += t.top();
                t.pop();
            }
        }

        // Bache hue characters stack se ans me daal do
        while (!t.empty()) {
            ans += t.top();
            t.pop();
        }

        return ans;
    }
};
