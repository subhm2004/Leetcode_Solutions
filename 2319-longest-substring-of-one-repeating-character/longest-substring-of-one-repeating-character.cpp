/*
    LeetCode 2213 - Longest Substring of One Repeating Character

    IDEA (ek line me):
    Har query me sirf ek character badalta hai -> point update.
    Aur humein poore string ka "longest same-char run" chahiye -> root ka answer.
    Yehi to Segment Tree ka bread & butter hai. O((n + k) log n).

    Har node 5 cheezein store karega apne segment [l, r] ke liye:
      1. max_Len     -> is segment ke andar sabse lamba same-char run
      2. left_Char   -> segment ka pehla character (s[l])
      3. left_Len    -> prefix run ki length (start se kitne same char chal rahe)
      4. right_Char  -> segment ka last character (s[r])
      5. right_Len   -> suffix run ki length (end tak kitne same char chal rahe)

    Prefix/suffix isliye chahiye kyunki answer border pe ban sakta hai:
    left child ka suffix + right child ka prefix jud kar bada run bana sakte hain.
*/

struct Node {
    int max_Len;      // is segment me longest repeating-char substring
    char left_Char;   // segment ka first char
    int left_Len;     // prefix me kitne same char consecutive
    char right_Char;  // segment ka last char
    int right_Len;    // suffix me kitne same char consecutive
    int l, r;         // segment ki boundaries (length nikalne ke liye: r - l + 1)
};

class SegmentTree {
    int n;
    vector<Node> segTree;

    /*
        MERGE = poore solution ka dil.
        Do bachhon ka info leke parent ka info banata hai.
        Yaad rakho: left ka segment right ke bilkul pehle hai (contiguous),
        isliye left.right_Char aur right.left_Char aapas me touch karte hain.
    */
    Node merge(const Node& left, const Node& right) {
        Node ans;

        // Parent ka range = left ka start se right ka end tak
        ans.l = left.l;
        ans.r = right.r;

        // Parent ka pehla char = left ka pehla char
        // Parent ka last char  = right ka last char
        ans.left_Char = left.left_Char;
        ans.right_Char = right.right_Char;

        // ---------- PREFIX (left_Len) nikalo ----------
        // Default: jitna left child ka prefix tha
        ans.left_Len = left.left_Len;

        // Special case: agar left child POORA hi ek hi char ka bana hai
        // (left.left_Len == left ki full length) AUR left ka last char
        // right ke first char se match karta hai -> prefix right me bhi ghus jaayega
        // Example: left = "aaa", right = "aab"  ->  parent prefix = 3 + 2 = 5
        if (left.left_Len == (left.r - left.l + 1) &&
            left.right_Char == right.left_Char) {
            ans.left_Len += right.left_Len;
        }

        // ---------- SUFFIX (right_Len) nikalo ----------
        // Default: jitna right child ka suffix tha
        ans.right_Len = right.right_Len;

        // Special case (mirror image): agar right child POORA ek hi char ka hai
        // aur uska first char left ke last char se match karta hai
        // -> suffix left ke andar tak extend ho jaayega
        // Example: left = "baa", right = "aaa"  ->  parent suffix = 3 + 2 = 5
        if (right.right_Len == (right.r - right.l + 1) &&
            right.left_Char == left.right_Char) {
            ans.right_Len += left.right_Len;
        }

        // ---------- ANSWER (max_Len) nikalo ----------
        // Candidate 1 & 2: dono bachhon ke apne-apne best answers
        ans.max_Len = max(left.max_Len, right.max_Len);

        // Candidate 3: BORDER wala run.
        // Agar left ka last char == right ka first char, to left ka suffix
        // aur right ka prefix mil kar ek naya (possibly bada) run banate hain.
        // Example: left = "ccbb", right = "bbba"  ->  2 + 3 = 5
        if (left.right_Char == right.left_Char) {
            ans.max_Len = max(ans.max_Len, left.right_Len + right.left_Len);
        }

        return ans;
    }

    /*
        BUILD - classic recursive build, O(n).
        Leaf pe har cheez trivially 1 hoti hai (single char = run of length 1).
    */
    void build(const string& s, int node, int l, int r) {
        if (l == r) {
            // {max_Len, left_Char, left_Len, right_Char, right_Len, l, r}
            segTree[node] = {1, s[l], 1, s[l], 1, l, r};
            return;
        }

        int mid = (l + r) / 2;

        build(s, 2 * node + 1, l, mid);       // left child
        build(s, 2 * node + 2, mid + 1, r);   // right child

        // Bachhe ban gaye -> ab unse parent banao
        segTree[node] = merge(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    /*
        POINT UPDATE - idx wale character ko val se replace karo.
        Sirf ek root-to-leaf path affect hota hai -> O(log n).
    */
    void update(int node, int l, int r, int idx, char val) {
        if (l == r) {
            // Leaf mil gaya, naya char set kar do (baaki sab wapas 1)
            segTree[node] = {1, val, 1, val, 1, l, r};
            return;
        }

        int mid = (l + r) / 2;

        // idx kis taraf hai, sirf usi side me jao (dusri branch chhod do)
        if (idx <= mid) {
            update(2 * node + 1, l, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, r, idx, val);
        }

        // Wapas aate waqt parent ko dobara merge karke fix karo
        segTree[node] = merge(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

public:
    SegmentTree(const string& s) {
        n = s.size();
        segTree.resize(4 * n);   // 4*n safe upper bound hota hai segment tree ke liye

        build(s, 0, 0, n - 1);   // root = index 0, range = [0, n-1]
    }

    // Public wrapper - user ko internal node/l/r ki tension nahi leni padti
    void update(int idx, char val) { update(0, 0, n - 1, idx, val); }

    // Root (index 0) hamesha poore string [0, n-1] ka answer rakhta hai
    int get_Max_Len() { return segTree[0].max_Len; }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        SegmentTree seg(s);   // O(n) build

        vector<int> ans;
        ans.reserve(queryIndices.size());   // chhota optimization, reallocation bachta hai

        for (int i = 0; i < queryIndices.size(); i++) {
            // Query i: index queryIndices[i] pe char queryCharacters[i] daalo
            seg.update(queryIndices[i], queryCharacters[i]);   // O(log n)

            // Update ke turant baad root ka answer hi is query ka jawab hai
            ans.push_back(seg.get_Max_Len());
        }

        return ans;
    }
};

/*
    COMPLEXITY:
        Build   -> O(n)
        Update  -> O(log n) per query
        Total   -> O(n + k log n),  Space O(n)

    DRY RUN (s = "babacc", query 1: index 1 -> 'b'):
        String ban gaya "bbbacc"
        Leaves: b b b a c c
        Left half [0,2] = "bbb"  -> max=3, pre=3, suf=3, lc='b', rc='b'
        Right half [3,5] = "acc" -> max=2, pre=1, suf=2, lc='a', rc='c'
        Merge: left.rc='b' != right.lc='a' -> border wala case nahi lagta
               max = max(3, 2) = 3   -> answer 3
*/