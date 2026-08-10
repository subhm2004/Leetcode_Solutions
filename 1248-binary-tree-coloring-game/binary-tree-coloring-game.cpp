class Solution {
public:
    // x wale node ke left aur right subtree ka size
    // dfs ke andar se set hote hain, isliye class-level pe
    int leftCount = 0;
    int rightCount = 0;

    // ════════════════════════════════════════════════════════════════════
    // dfs: har subtree ka size return karta hai
    // Side effect: jab x wala node mile, uske left/right subtree size save
    // ────────────────────────────────────────────────────────────────────
    // POST-ORDER hai — pehle bachche count karo, phir khud ko
    // COMPLEX: O(n)
    // ════════════════════════════════════════════════════════════════════
    int dfs(TreeNode* root, int x) {
        if (root == NULL)
            return 0;

        int left  = dfs(root->left, x);    // left subtree me kitne nodes
        int right = dfs(root->right, x);   // right subtree me kitne nodes

        // x mil gaya → uske dono subtree ke size pakad lo
        // (ye poore game ka decision inhi 2 numbers pe tikka hai)
        if (root->val == x) {
            leftCount  = left;
            rightCount = right;
        }

        return left + right + 1;   // +1 khud ke liye
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {

        dfs(root, x);

        // ── Teesra region: x ke "upar" wala poora hissa ──
        // Poora tree = x ka left + x ka right + x khud + baaki sab
        // → parentCount = n - left - right - 1
        int parentCount = n - leftCount - rightCount - 1;

        // ── GAME KA CORE INSIGHT ──
        // x color hone ke baad tree 3 alag REGIONS me bat jata hai:
        //
        //            parentCount  (x ke parent ki taraf ka sab kuch)
        //                 |
        //                 x
        //                / \
        //      leftCount    rightCount
        //
        // x ek "deewar" ka kaam karta hai — ye 3 region ek doosre se
        // sirf x ke through jud sakte the, aur x already colored hai.
        //
        // Player 2 (main) ko y chunna hai. Best strategy: x ke bilkul
        // paas wale node pe baithna — x ka parent, ya left child,
        // ya right child. Isse:
        //   • main us POORE region ko capture kar leta hoon (blocked nahi)
        //   • Player 1 baaki 2 region hi le pata hai
        //
        // Kyun poora region milta hai? Kyunki x pehle se colored hai,
        // to player 1 us region me ghus hi nahi sakta — ek hi raasta
        // tha aur wo x se hoke jata hai.
        int mx = max({leftCount, rightCount, parentCount});

        // Jeetne ke liye SAKHTI se aadhe se zyada chahiye.
        // n odd hai → n/2 integer division se floor milta hai
        // (n=11 → n/2=5 → mx >= 6 chahiye, matlab baaki ko max 5 milega)
        // Tie possible nahi kyunki n odd hai.
        return mx > n / 2;
    }
};