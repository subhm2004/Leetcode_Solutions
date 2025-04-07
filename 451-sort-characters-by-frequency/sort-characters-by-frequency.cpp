class Solution {
public:
    string frequencySort(string s) {
        // ASCII characters ke liye frequency array bana rahe hain
        vector<int> freq(128, 0);

        // Har character ki frequency count kar rahe hain
        for (char c : s) {
            freq[c]++;
        }

        // Har character ko uski frequency ke saath pair karke store kar rahe hain
        vector<pair<char, int>> chars;
        for (int i = 0; i < 128; ++i) {
            if (freq[i] > 0) {
                chars.push_back({(char)i, freq[i]});
            }
        }

        // Characters ko frequency ke basis pe descending order mein sort kar rahe hain
        sort(chars.begin(), chars.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        // Final result string bana rahe hain — har character ko uski frequency ke times add kar rahe hain
   
    //     string result;
    //     for (auto& [ch, count] : chars) {
    //         result += string(count, ch);
    //     }

    //     return result;
        string result;
        for (auto& [ch, count] : chars) {
            // Loop se character ko 'count' times result mein add kar rahe hain
            for (int i = 0; i < count; ++i) {
                result += ch;
            }
        }

        return result;
    }
};
