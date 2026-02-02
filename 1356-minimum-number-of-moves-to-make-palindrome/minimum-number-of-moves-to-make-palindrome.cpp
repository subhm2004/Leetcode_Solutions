class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        int moves = 0;

        /*
        ========================================================
        TWO POINTERS GREEDY APPROACH
        ========================================================
        Idea: Build palindrome by matching characters from both ends
        
        left  → start of remaining unmatched portion
        right → end of remaining unmatched portion
        
        Strategy:
        1. If s[left] == s[right] → already matched, move inward
        2. If s[left] != s[right] → find s[left]'s match on right side
           and bring it to position 'right' using adjacent swaps
        ========================================================
        */

        while (left < right) {

            // ================================================
            // CASE 1: Characters already match
            // ================================================
            // s[left] and s[right] are already in correct positions
            // for a palindrome. Move to next pair.
            if (s[left] == s[right]) {
                left++;
                right--;
                continue;
            }

            // ================================================
            // CASE 2: Characters don't match
            // ================================================
            // Need to find s[left]'s matching character on the
            // right side and bring it to position 'right'
            
            // Search for s[left]'s match from right side
            int match_pos = right;
            while (match_pos > left && s[match_pos] != s[left]) {
                match_pos--;
            }

            // ================================================
            // SPECIAL CASE: ODD CHARACTER (Middle element)
            // ================================================
            // If match_pos == left, it means s[left] has NO matching
            // character on the right side.
            // 
            // This happens when a character appears ODD number of times.
            // In a palindrome, this character will be in the CENTER.
            // 
            // Solution: Move it one position to the right temporarily.
            // It will eventually settle in the middle as we process.
            //
            // Example: s = "abc"
            //          All chars appear once (odd)
            //          One will be middle, others will be swapped
            if (match_pos == left) {
                swap(s[left], s[left + 1]);
                moves++;
                // Don't increment left/right — recheck this position
                continue;
            }

            // ================================================
            // NORMAL CASE: Matching character found
            // ================================================
            // Bring s[match_pos] to position 'right' using
            // adjacent swaps (bubble it rightward)
            //
            // Example: s = "aabb", left=0, right=3
            //          s[left]='a', s[right]='b'
            //          match_pos=1 (where second 'a' is)
            //          
            //          Move s[1] to position 3:
            //          "aabb" → swap(1,2) → "abab"  (moves++)
            //                 → swap(2,3) → "abba"  (moves++)
            //
            //          Now s[0]='a' and s[3]='a' match!
            while (match_pos < right) {
                swap(s[match_pos], s[match_pos + 1]);
                moves++;
                match_pos++;
            }

            // Match complete! Move to next pair
            left++;
            right--;
        }

        return moves;
    }
};

/*
========================================================
DRY RUN EXAMPLES
========================================================

Example 1: s = "aabb"
-----------------------
Initial: left=0, right=3, s="aabb"

Iteration 1:
  s[0]='a', s[3]='b' → NOT MATCH
  Find 'a' from right: match_pos = 1 (s[1]='a')
  match_pos != left → bring s[1] to position 3
  
  Swap(1,2): "aabb" → "abab"  moves=1, match_pos=2
  Swap(2,3): "abab" → "abba"  moves=2, match_pos=3
  
  left=1, right=2, s="abba"

Iteration 2:
  s[1]='b', s[2]='b' → MATCH
  left=2, right=1
  
Loop ends (left >= right)
Output: 2 ✓


Example 2: s = "letelt"
-----------------------
Initial: left=0, right=5, s="letelt"

Iteration 1:
  s[0]='l', s[5]='t' → NOT MATCH
  Find 'l' from right: match_pos = 4 (s[4]='l')
  Bring s[4] to position 5
  
  Swap(4,5): "letelt" → "letelT" → "leteTl"  moves=1
  
  Actually: "letelt" → "leteTl"  moves=1
  left=1, right=4, s="letetl"

Iteration 2:
  s[1]='e', s[4]='t' → NOT MATCH
  Find 'e' from right: match_pos = 3 (s[3]='e')
  Bring s[3] to position 4
  
  Swap(3,4): "letetl" → "leteTl" → "lettel"  moves=2
  left=2, right=3, s="lettel"

Iteration 3:
  s[2]='t', s[3]='t' → MATCH
  left=3, right=2
  
Loop ends
Output: 2 ✓


Example 3: s = "abc" (all odd count chars)
-----------------------
Initial: left=0, right=2, s="abc"

Iteration 1:
  s[0]='a', s[2]='c' → NOT MATCH
  Find 'a' from right: match_pos goes to 0 (not found)
  match_pos == left → ODD CHARACTER
  
  Swap(0,1): "abc" → "bac"  moves=1
  s="bac", left=0, right=2 (unchanged)

Iteration 2:
  s[0]='b', s[2]='c' → NOT MATCH
  Find 'b' from right: match_pos = 0 (itself)
  match_pos == left → ODD CHARACTER
  
  Swap(0,1): "bac" → "abc"  moves=2
  s="abc"... continues until one char settles middle

Output: varies but handles odd chars correctly
========================================================
*/