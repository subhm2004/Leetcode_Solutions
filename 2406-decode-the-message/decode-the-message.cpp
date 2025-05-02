class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> charMap;
        char currentChar = 'a';
        
        // Iterate through the key and assign characters to the map
        for (char c : key) {
            if (c != ' ' && charMap.find(c) == charMap.end()) {
                charMap[c] = currentChar++;
            }
        }
        
        // Transform the message using the map
        for (int i = 0; i < message.size(); i++) {
            if (message[i] != ' ') {
                message[i] = charMap[message[i]];
            }
        }
        
        return message;
    }
};
