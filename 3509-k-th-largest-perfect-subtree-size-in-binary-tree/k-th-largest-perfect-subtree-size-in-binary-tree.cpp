class Solution {
public:
    vector<int> sizes;   /* har perfect subtree ka size yahan collect hoga */

    /* ═══════════════════════════════════════════════════════════════════════
       dfs: agar ye subtree PERFECT hai to uski HEIGHT return karo,
            warna -1 return karo.

       POST-ORDER kyun?
         "Kya main perfect hoon?" ka jawab mere bachchon pe depend karta hai.
         Isliye pehle dono bachche solve karo, PHIR apna decision lo.

       -1 sentinel ka fayda:
         Ek hi return value me DO cheezein pack ho gayi —
           "perfect hoon ya nahi"  +  "meri height kitni hai"
         Height kabhi negative nahi hoti, isliye -1 safe sentinel hai.
         (warna pair<bool,int> return karna padta)

       COMPLEX: O(n) — har node exactly ek baar visit
       ═══════════════════════════════════════════════════════════════════════ */
    int dfs(TreeNode* root) {

        /* Khali tree bhi technically perfect hai, uski height 0.
           Ye base case hi leaf ko kaam karwata hai:
             leaf ke dono bachche NULL → lh = 0, rh = 0 → barabar ✓
             → leaf ki height 1, size (1<<1)-1 = 1  ✓                        */
        if (root == nullptr)
            return 0;

        int lh = dfs(root->left);    /* pehle left bachcha  */
        int rh = dfs(root->right);   /* phir right bachcha  */

        /* ── Ab khud ka decision (post-order ka "post" wala hissa) ──
           Main perfect tabhi hoon jab TEENO shartein poori hon:
             1) lh != -1  → left bachcha perfect hai
             2) rh != -1  → right bachcha perfect hai
             3) lh == rh  → dono ki height BARABAR hai

           Teesri shart kyun? Perfect ki definition hai "saare leaves ek hi
           level pe". Agar left ki height 2 aur right ki 3 hui, to left wale
           leaves upar reh jayenge → perfect nahi.

                   O           lh = 2, rh = 3  →  ALAG  →  return -1
                  / \
                 O   O
                /|   |\
               O O   O O
                    /| |\
                   O O O O   ← ye leaves neeche hain, baaki upar   */
        if (lh == -1 || rh == -1 || lh != rh)
            return -1;

        /* Yahan pahunche matlab main PERFECT hoon.
           Meri height = bachche ki height + 1 (khud ka level jud gaya)      */
        int h = lh + 1;

        /* ── Size nikalo: 2^h - 1 ──
           levels ke nodes: 1 + 2 + 4 + ... + 2^(h-1)  =  2^h - 1

             h=1 →  1  (2-1)
             h=2 →  3  (4-1)
             h=3 →  7  (8-1)

           (1 << h) hi 2^h hai — left shift = 2 se multiply
             1 << 3 = 1000 (binary) = 8                                     */
        sizes.push_back((1 << h) - 1);

        return h;   /* apne parent ko height bata do */
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {

        dfs(root);   /* poora tree ghoomo, saare perfect subtrees collect ho jayenge */

        /* itne perfect subtrees hain hi nahi → -1
           (int) cast: sizes.size() size_t hai, k int — warning se bachne ko */
        if ((int)sizes.size() < k)
            return -1;

        /* ── DESCENDING sort ──
           greater<int>() comparator "bada pehle" wala order deta hai
           [1,3,1,7,1] → [7,3,1,1,1]                                        */
        sort(sizes.begin(), sizes.end(), greater<int>());

        /* k is 1-indexed, array 0-indexed → k-1
           k=1 → sizes[0] (sabse bada)
           k=2 → sizes[1] (doosra sabse bada)                               */
        return sizes[k - 1];
    }
};