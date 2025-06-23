class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort by height descending, then by k ascending
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) return a[0] > b[0];  // Taller first
            return a[1] < b[1];                   // Smaller k first
        });
        
        vector<vector<int>> ans;
        
        // Insert each person at their k-th position
        for (auto& person : people) {
            int k = person[1];  // k position nikalo
            ans.insert(ans.begin() + k, person);
        }
        
        return ans;
    }
};

/*
EXAMPLE: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]

STEP 1 - Sort by height (desc), then k (asc):
[[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]

STEP 2 - Process each person:

Process [7,0]: Insert at position 0
Result: [[7,0]]

Process [7,1]: Insert at position 1  
Result: [[7,0], [7,1]]

Process [6,1]: Insert at position 1
Result: [[7,0], [6,1], [7,1]]

Process [5,0]: Insert at position 0
Result: [[5,0], [7,0], [6,1], [7,1]]

Process [5,2]: Insert at position 2
Result: [[5,0], [7,0], [5,2], [6,1], [7,1]]

Process [4,4]: Insert at position 4
Result: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

FINAL ANSWER: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

WHY IT WORKS:
- Process tallest people first
- When inserting at k-th position, exactly k taller people will be in front
- Shorter people added later don't affect taller people's counts
*/