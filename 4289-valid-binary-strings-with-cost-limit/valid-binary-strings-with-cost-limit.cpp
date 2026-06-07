class Solution {
public:
    vector<string> ans;

    void backtrack(int idx, int n, int k, int cost, string& curr, bool prev_one ) {

        if (idx == n) {
            ans.push_back(curr);
            return;
        }

        // Put '0'
        curr.push_back('0');
        backtrack(idx + 1, n, k, cost, curr, false);
        curr.pop_back();

        // Put '1'
        if (prev_one == false && cost + idx <= k) {
            curr.push_back('1');
            backtrack(idx + 1, n, k, cost + idx, curr, true);
            curr.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        string curr;
        backtrack(0, n, k, 0, curr, false);

        return ans;
    }
};