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

    int bfs(vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            vector<int>& initialBoxes) {

        queue<int> q; // Boxes jo open ho chuke hain
        unordered_map<int, bool> hasBox;       // Boxes jo humein mil chuke hain
        unordered_map<int, bool> opened;       // Boxes jo already open ho gaye hain

        // Initial boxes ke liye setup
        for (int box : initialBoxes) {
            hasBox[box] = true; // Yeh box humein mila hai

            if (status[box] == 1) {
                q.push(box);       // Agar open hai toh BFS ke liye ready
                opened[box] = true;
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            totalCandies += candies[curr]; // Current box ki candies le lo

            // Current box ke keys se naye boxes unlock karo
            for (int key : keys[curr]) {
                status[key] = 1; // Box ab open ho sakta hai

                // Agar key se milne wala box already mila ho aur abhi open na hua ho
                if (hasBox[key] && !opened[key]) {
                    q.push(key);
                    opened[key] = true;
                }
            }

            // Current box ke andar jo boxes hain unko bhi consider karo
            for (int innerBox : containedBoxes[curr]) {
                hasBox[innerBox] = true; // Yeh box ab mil gaya

                // Agar open kar sakte ho aur abhi tak open nahi hua toh queue mein daal do
                if (status[innerBox] == 1 && !opened[innerBox]) {
                    q.push(innerBox);
                    opened[innerBox] = true;
                }
            }
        }

        return totalCandies;
    }


    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        // int total_Candies = 0;
        // unordered_map<int, bool> visited;      // Jo boxes humne khol liye
        // unordered_map<int, bool> waitingBoxes; // Jo boxes mil gaye par locked hain

        // // Har initial box ke liye DFS chalao
        // for (int box : initialBoxes) {
        //     total_Candies += dfs(box, status, candies, keys, containedBoxes, visited, waitingBoxes);
        // }

        // return total_Candies;
        return bfs(status, candies, keys, containedBoxes, initialBoxes);

    }
};
