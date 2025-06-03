class Solution {
public:
    // DFS function jo ek box se start karke sare possible candies collect karega
    int dfs(int box, vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            unordered_map<int, bool>& visited, unordered_map<int, bool>& waitingBoxes) {

        // Agar box already open ho chuka hai, toh kuch bhi mat karo
        if (visited[box]) return 0;

        // Agar box locked hai, toh usse waiting mein daal do
        if (status[box] == 0) {
            waitingBoxes[box] = true;
            return 0;
        }

        // Ab box open ho gaya, mark kar do visited mein
        visited[box] = true;
        int total = candies[box]; // Us box ki candies le lo

        // Jo boxes is box ke andar hain, unko bhi explore karo
        for (int contained : containedBoxes[box]) {
            total += dfs(contained, status, candies, keys, containedBoxes, visited, waitingBoxes);
        }

        // Jo keys is box ke andar hain, unse naye boxes unlock karo
        for (int key : keys[box]) {
            status[key] = 1; // Box ab open ho sakta hai
            // Agar key se unlock hone wala box already mila tha, ab usko bhi khol lo
            if (waitingBoxes[key]) {
                total += dfs(key, status, candies, keys, containedBoxes, visited, waitingBoxes);
            }
        }

        return total;
    }

    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int total_Candies = 0;
        unordered_map<int, bool> visited;      // Jo boxes humne khol liye
        unordered_map<int, bool> waitingBoxes; // Jo boxes mil gaye par locked hain

        // Har initial box ke liye DFS chalao
        for (int box : initialBoxes) {
            total_Candies += dfs(box, status, candies, keys, containedBoxes, visited, waitingBoxes);
        }

        return total_Candies;
    }
};
