class Solution {
public:
    // Function jo maximum k consonants tak valid substrings count karega
    long count_Sub_strings_With_At_Most_K(const string& word, int k) {
        if (k < 0) return 0; // Agar k negative hai toh koi valid substring nahi ho sakti

        long ans = 0; // Substrings ka count store karega
        int vowel_Count = 0, unique_Vowels = 0; // Total vowels aur unique vowels track karega
        int vowel_Seen[5] = {-1, -1, -1, -1, -1}; // 'a', 'e', 'i', 'o', 'u' ka last index store karega
        int left = 0, consonant_Count = 0; // Sliding window ka left pointer aur consonant count

        for (int right = 0; right < word.length(); ++right) {
            char c = word[right];

            // Agar character vowel hai toh uska index track karein
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                int index = (c == 'a') ? 0 : (c == 'e') ? 1 : (c == 'i') ? 2 : (c == 'o') ? 3 : 4;
                
                if (vowel_Seen[index] < left)
                    unique_Vowels++; // Agar naya vowel mile toh unique vowel count badhayein
                
                vowel_Seen[index] = right; // Current vowel ka last occurrence store karein
                vowel_Count++; // Total vowels badhayein
            } else {
                consonant_Count++; // Consonant count badhayein
            }

            // Agar consonant count limit se zyada ho gaya toh left pointer ko move karein
            while (consonant_Count > k) {
                char leftChar = word[left];
                
                if (leftChar == 'a' || leftChar == 'e' || leftChar == 'i' || leftChar == 'o' || leftChar == 'u') {
                    int index = (leftChar == 'a') ? 0 : (leftChar == 'e') ? 1 : (leftChar == 'i') ? 2 : (leftChar == 'o') ? 3 : 4;
                    
                    if (vowel_Seen[index] == left)
                        unique_Vowels--; // Agar removing character last occurrence hai toh unique vowel kam karein
                    
                    vowel_Count--; // Total vowel count kam karein
                } else {
                    consonant_Count--; // Consonant count kam karein
                }
                
                left++; // Left pointer aage badhayein
            }

            // Jab saare vowels ek baar aa jaye aur consonant count valid ho
            if (unique_Vowels == 5) {
                int leftmostVowel = *min_element(vowel_Seen, vowel_Seen + 5); // Sabse left waala vowel ka index
                ans += (leftmostVowel - left + 1); // Valid substrings ka count update karein
            }
        }

        return ans;
    }

    // Function jo exactly k consonants wale substrings count karega
    long long countOfSubstrings(string word, int k) {
        return count_Sub_strings_With_At_Most_K(word, k) - count_Sub_strings_With_At_Most_K(word, k - 1);
    }
};


// class Solution {
// public:
//     long long countOfSubstrings(string word, int k) {
//         int n = word.length();
//         int count = 0;  // Yeh final count hoga jo required substrings ko
//         store karega

//         // Har possible substring ke liye check karne ke liye 'start' ko
//         iterate karenge for (int start = 0; start < n; ++start) {
//             int vowelsCount[5] = {0};  // Har baar naye substring ke liye
//             vowels count anset hoga int consonant_Count = 0;    // Har baar
//             naye substring ke liye consonant count bhi anset hoga

//             // Yeh 'end' pointer har possible substring ke end ko repansent
//             karega for (int end = start; end < n; ++end) {
//                 char c = word[end];  // Current character ko fetch kar rahe
//                 hain

//                 // Agar vowel hai toh uska count badhane ke liye usko
//                 anspective array index pe increment karenge if (c == 'a')
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
//                     consonant_Count++;  // Agar consonant hai toh uska count
//                     badhao

//                 // Agar consonant count k se zyada ho gaya toh aage dekhne ka
//                 koi fayda nahi if (consonant_Count > k) {
//                     break;
//                 }

//                 // Check kar rahe hain ki saare vowels at least ek baar aaye
//                 hain ya nahi if (vowelsCount[0] > 0 && vowelsCount[1] > 0 &&
//                     vowelsCount[2] > 0 && vowelsCount[3] > 0 &&
//                     vowelsCount[4] > 0 && consonant_Count == k) {
//                     ++count;  // Agar condition satisfy ho gayi toh count
//                     badha do
//                 }
//             }
//         }
//         return count;  // Final count return karenge
//     }
// };
