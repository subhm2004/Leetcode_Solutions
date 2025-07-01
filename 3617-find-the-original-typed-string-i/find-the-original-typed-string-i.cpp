// class Solution {
// public:
//     int dfs(const vector<pair<char, int>>& groups, int i, bool removed) {
//         if (i == groups.size()) return 1;

//         int total = 0;

//         // Case 1: Don't remove anything from this group
//         total += dfs(groups, i + 1, removed);

//         // Case 2: Remove 1 char from this group
//         if (!removed && groups[i].second > 1) {
//             //Agar hum current group me se ek character hataate hain, to kitne valid strings ban sakte hain uske baad ke groups se (size -1) is liye kiya h kyoki agar ek hata diya to baki k bhi to same hi elemts hai count hi -1  hua hai baki hatauga tab bhi same hi answe aana hai to simple ek hatauga to bakiyo ka kya answer aayega uska ye hi hai 
//             total += (groups[i].second - 1) * dfs(groups, i + 1, true);
//         }

//         return total;
//     }

//     int possibleStringCount(string word) {
//         unordered_map<char, int> mp;

//         for (char ch : word) {
//             mp[ch]++;
//         }

//          vector<pair<char, int>> groups;
//         for (auto& [ch, freq] : mp) {
//             groups.emplace_back(ch, freq);
//         }

//         return dfs(groups, 0, false); // Ab tak koi bhi group me se character remove nahi kiya gaya isliye humne false pass kiya hai question me


//     }
// };
class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0;

        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1])
                count++;
        }

        return count+1; //+1 for when Alice does no long press
    }
};

