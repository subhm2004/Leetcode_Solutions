// class Solution {
// public:
//     int minimumCardPickup(vector<int>& cards) {
//         int n = cards.size();
//         int min_len = INT_MAX;

//         for (int i = 0; i < n; i++) {
//             unordered_set<int> seen; // store elements in current subarray
//             for (int j = i; j < n; j++) {
//                 if (seen.count(cards[j])) {
//                     min_len = min(min_len, j - i + 1); 
//                     break; // once found duplicate, no need to expand this subarray
//                 }
//                 seen.insert(cards[j]);
//             }
//         }

//         return (min_len == INT_MAX) ? -1 : min_len;
//     }
// };

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> last_seen; // val -> idx store hoga 
        int min_len = INT_MAX;
        
        for (int i = 0; i < cards.size(); i++) {
            if (last_seen.count(cards[i])) {
                min_len = min(min_len, i - last_seen[cards[i]] + 1);
            }
            last_seen[cards[i]] = i;
        }
        
        return (min_len == INT_MAX) ? -1 : min_len;
    }
};