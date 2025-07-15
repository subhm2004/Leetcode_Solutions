class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> types;
        for (auto& candy : candyType) {
            types.insert(candy);
        }

        int allowed = n / 2;
        return min((int)types.size(), allowed);
    }
};
