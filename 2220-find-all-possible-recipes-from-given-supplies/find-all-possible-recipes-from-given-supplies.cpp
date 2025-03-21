class Solution {
public:
    vector<string> topoSortBfs(vector<string>& recipes,
                               unordered_map<string, list<string>>& adjList,
                               unordered_map<string, int>& inDegree,
                               unordered_set<string>& suppliesSet) {
        vector<string> ans;
        queue<string> q;

        // In-degree = 0 wali recipes ko queue me dalenge
        for (string& recipe : recipes) {
            if (inDegree[recipe] == 0) {
                q.push(recipe);
            }
        }

        // BFS se Topological Sort perform karenge
        while (!q.empty()) {
            string fNode = q.front();
            q.pop();
            ans.push_back(fNode); // Recipe ko answer list me add karenge
            suppliesSet.insert(fNode); // Ab ye bhi supply ka part ban gaya

            // Is recipe se dependent recipes ka in-degree kam karenge
            for (const string& nbr : adjList[fNode]) {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0) { // Agar in-degree 0 ho jaye to queue me push karenge
                    q.push(nbr);
                }
            }
        }

        return ans; // Final list of recipes jo ban sakti hain
    }

    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        vector<string> ans;
        unordered_map<string, list<string>> adjList; // Graph ke liye adjacency list
        unordered_map<string, int> inDegree; // Har node ka in-degree track karne ke liye
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end()); // Supplies ko set me convert kar rahe hain fast lookup ke liye

        // Graph banayenge jisme ingredients se recipes ka mapping hoga
        for (int i = 0; i < recipes.size(); ++i) {
            for (string& ingredient : ingredients[i]) {
                if (!suppliesSet.contains(ingredient)) { // Agar ingredient pehle se supply me nahi hai to usko graph me add karenge
                    adjList[ingredient].push_back(recipes[i]); // Ingredient -> dependent recipe
                    inDegree[recipes[i]]++; // Recipe ka in-degree badh jayega
                }
            }
        }

        // BFS based topological sort call karenge
        return topoSortBfs(recipes, adjList, inDegree, suppliesSet);
    }
};
