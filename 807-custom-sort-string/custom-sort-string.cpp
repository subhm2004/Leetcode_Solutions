// class Solution {    // accept ho gya hai ye acha solution hai 
// public:
//     string customSortString(string order, string s) {
//         // Step 1: har character ka frequency count nikalna
//         vector<int> freq(26, 0);  
//         for (char c : s) {
//             freq[c - 'a']++;  // jo char mila uska count ++
//         }

//         string ans;

//         // Step 2: pehle order ke hisaab se characters daalna
//         for (char c : order) {
//             while (freq[c - 'a'] > 0) {   // jab tak count > 0 hai
//                 ans.push_back(c);      // char ko ans me daalo
//                 freq[c - 'a']--;          // count kam karo
//             }
//         }

//         // Step 3: jo characters order me nahi the, unko baad me daalo
//         for (char c = 'a'; c <= 'z'; c++) {
//             while (freq[c - 'a'] > 0) {
//                 ans.push_back(c);
//                 freq[c - 'a']--;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string customSortString(string order, string s) {
        // Step 1: rank mapping for each char
        unordered_map<char, int> rank;
        for (int i = 0; i < order.size(); i++) {
            rank[order[i]] = i;  // smaller index = higher priority
        }

        // Step 2: sort s using custom comparator
        sort(s.begin(), s.end(), [&](char a, char b) {
            int rankA = rank.count(a) ? rank[a] : 26; // if not in order, put at end
            int rankB = rank.count(b) ? rank[b] : 26;
            return rankA < rankB;
        });

        return s;
    }
};
