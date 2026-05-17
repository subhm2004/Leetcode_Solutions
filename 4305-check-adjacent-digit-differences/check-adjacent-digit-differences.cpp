class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 1; i < s.size(); i++)
        {
            int diff = abs(s[i] - s[i - 1]);

            if (diff > 2)
                return false;
        }

        return true;
    }
};