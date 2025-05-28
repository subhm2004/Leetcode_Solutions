class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> value_To_Weight; // stores value -> total weight

        // Add weights from items1
        for (auto& item : items1) {
            value_To_Weight[item[0]] += item[1];
        }

        // Add weights from items2
        for (auto& item : items2) {
            value_To_Weight[item[0]] += item[1];
        }

        // Convert the map to a 2D vector
        vector<vector<int>> ans;
        for (auto& [value, weight] : value_To_Weight) {
            ans.push_back({value, weight});
        }

        return ans;
    }
};
