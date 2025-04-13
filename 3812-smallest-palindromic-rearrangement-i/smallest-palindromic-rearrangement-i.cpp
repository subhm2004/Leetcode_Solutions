class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> freq;
        
        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }
        
        string firstHalf = "";
        char middle = '\0';  // to store the middle character if there's one with odd frequency
        
        // Step 2: Build the first half and check for middle character
        for (auto& [c, count] : freq) {
            if (count % 2 == 0) {
                // Add half of the character count to the first half
                firstHalf += string(count / 2, c);
            } else {
                // If there's a character with an odd count, it will go in the middle
                if (middle == '\0' || c < middle) {
                    middle = c;  // update to lexicographically smallest odd character
                }
                firstHalf += string(count / 2, c);
            }
        }
        
        // Step 3: Sort the first half lexicographically
        sort(firstHalf.begin(), firstHalf.end());
        
        // Step 4: Construct the second half as the reverse of the first half
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        
        // Step 5: Build the final palindrome
        string result = firstHalf;
        if (middle != '\0') {
            result += middle;  // add the middle character if it exists
        }
        result += secondHalf;
        
        return result;
    }
};
