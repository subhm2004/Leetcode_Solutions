// class Solution {
// public:
// int countOfSubstrings(string word, int k) {
//         int n = word.length();
//         int count = 0;

//         for (int start = 0; start < n; ++start) {
//             int vowelsCount[5] = {0};
//             int consonantCount = 0;

//             for (int end = start; end < n; ++end) {
//                 char c = word[end];

//                 if (c == 'a')
//                     vowelsCount[0]++;
//                 else if (c == 'e')
//                     vowelsCount[1]++;
//                 else if (c == 'i')
//                     vowelsCount[2]++;
//                 else if (c == 'o')
//                     vowelsCount[3]++;
//                 else if (c == 'u')
//                     vowelsCount[4]++;
//                 else
//                     consonantCount++;

//                 if (consonantCount > k) {
//                     break;
//                 }

//                 if (vowelsCount[0] > 0 && vowelsCount[1] > 0 &&
//                     vowelsCount[2] > 0 && vowelsCount[3] > 0 &&
//                     vowelsCount[4] > 0 && consonantCount == k) {
//                     ++count;
//                 }
//             }
//         }

//         return count;
//     }
// };

class Solution {
public:
    long countSubstringsWithAtMostK(const string& word, int k) {
        if (k < 0) return 0;

        long ans = 0;
        int vowel_Count = 0, unique_Vowels = 0;
        int vowel_Seen[5] = {-1, -1, -1, -1, -1};  // 'a', 'e', 'i', 'o', 'u' ka last index
        int left = 0, consonant_Count = 0;

        for (int right = 0; right < word.length(); ++right) {
            char c = word[right];

            // Direct vowel check without extra function
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                int idx = (c == 'a') ? 0 : (c == 'e') ? 1 : (c == 'i') ? 2 : (c == 'o') ? 3 : 4;
                if (vowel_Seen[idx] < left) unique_Vowels++;  // Unique vowel encounter hua
                vowel_Seen[idx] = right;
                vowel_Count++;
            } else {
                consonant_Count++;  // Consonant mila toh count badhayein
            }

            // Jab consonant count limit cross kar le toh left pointer move karein
            while (consonant_Count > k) {
                char leftChar = word[left];
                if (leftChar == 'a' || leftChar == 'e' || leftChar == 'i' || leftChar == 'o' || leftChar == 'u') {
                    int idx = (leftChar == 'a') ? 0 : (leftChar == 'e') ? 1 : (leftChar == 'i') ? 2 : (leftChar == 'o') ? 3 : 4;
                    if (vowel_Seen[idx] == left) unique_Vowels--;  // Agar last vowel hat raha hai toh count kam karein
                    vowel_Count--;
                } else {
                    consonant_Count--;
                }
                left++;
            }

            // Jab saare vowels ek baar aa jaye aur consonant count limit ke andar ho
            if (unique_Vowels == 5) {
                ans += (*min_element(vowel_Seen, vowel_Seen + 5) - left + 1);
            }
        }

        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return countSubstringsWithAtMostK(word, k) - countSubstringsWithAtMostK(word, k - 1);
    }
};