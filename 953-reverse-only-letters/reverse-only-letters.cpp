class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {

            // Move left pointer to the next letter
            while (left < right && !isalpha(s[left])) left++;
            
            // Move right pointer to the previous letter
            while (left < right && !isalpha(s[right])) right--;

            // Swap letters
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};
