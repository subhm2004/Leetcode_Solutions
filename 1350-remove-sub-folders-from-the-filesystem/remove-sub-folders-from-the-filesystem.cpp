class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result;
        string prev = "";
        for (string& f : folder) {
            // If 'prev' is not a prefix or 'f' is not a subfolder, add to
            // result
            if (prev.empty() || f.substr(0, prev.size()) != prev ||
                f[prev.size()] != '/') {
                result.push_back(f);
                prev = f; // Update 'prev' to the current folder
            }
        }

        return result;
    }
};
