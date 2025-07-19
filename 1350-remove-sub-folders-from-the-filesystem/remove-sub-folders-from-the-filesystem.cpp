class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Pehle folders ko sort kar lete hai 
        // Taaki parent folders pehle aayen, sub-folders baad mein
        sort(folder.begin(), folder.end());

        vector<string> ans; 

        for (auto& path : folder) {
            // Step 2: Agar ans abhi empty hai, ya current path previous folder ka sub-folder nahi hai
            // Tabhi usse ans mein daalna hai

            // Example: agar ans.back() = "/a" hai
            // toh sub-folder hoga agar path = "/a/b", i.e., "/a/b".find("/a/") == 0
            if (ans.empty() || path.find(ans.back() + "/") != 0) {
                ans.push_back(path); // Sub-folder nahi hai, toh rakh lo
            }
        }

        return ans; 
    }
};
