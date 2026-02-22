class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> digitorial = {1, 2, 145, 40585};

        string target = to_string(n);
        sort(target.begin(), target.end());

        for (int x : digitorial)
        {
            string curr = to_string(x);

            if (curr.size() != target.size()) continue;

            sort(curr.begin(), curr.end());

            if (curr == target)
                return true;
        }

        return false;
    }
};