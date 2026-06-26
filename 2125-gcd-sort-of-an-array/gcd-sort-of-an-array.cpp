class Union_find
{
    vector<int> parent;
    vector<int> rank;

public:
    Union_find(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;  // har node apna khud ka parent (alag island)
        }
    }

    // Find with path compression
    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);  // path compression
    }

    void UNION_BY_RANK(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;  // already same set me hain

        if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};
class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        
        // STEP 1: Array me jo sabse bada number hai usko dhundo

        // Yeh isliye chahiye kyunki humein prime factors ke liye "virtual nodes" banane hain, aur unka range max_num tak ho sakta hai
        // Example: agar nums = [10, 5, 9, 3, 15], to max_num = 15
        int max_num = *max_element(nums.begin(), nums.end());
        
        // STEP 2: Union-Find data structure banao with proper size
         
        // OFFSET TRICK samajh: humein do alag type ki "cheezein" represent karni hain:
        //   (a) Actual numbers jo array me hain (jaise 10, 5, 9, 3, 15)
        //   (b) Prime factors jo unko divide karte hain (jaise 2, 3, 5)
        //
        // Dono ko ek hi Union-Find me daalna hai, lekin clash nahi hona chahiye
        // (kyunki number "5" aur prime "5" alag concept hain, par same integer value)
        //
        // Isliye trick: prime 'p' ko hum index (max_num + p) pe store karenge
        // Matlab: index 0 to max_num  -> actual numbers (jaise unka apna value index hai)
        //         index max_num+1 to 2*max_num -> prime markers (shifted by max_num)
        //
        // Total size chahiye: 2*max_num + 1 (0 se 2*max_num tak safely cover ho jaye)
        Union_find uf(2 * max_num + 1);
        
        // STEP 3: Har number ke prime factors nikaalo aur unhe union (connect) karo
        for (int num : nums) {
            
            // 'n' ek temporary copy hai 'num' ki, jisko hum tod-tod ke factor nikaalenge
            // (original 'num' ko intact rakhna hai kyunki baad me union me use karna hai)
            int n = num;
            
            // Trial division method: 2 se start karke √n tak primes check karo
            // Jab p*p > n ho jaye, to baaki bacha factor khud hi prime hota hai (neeche handle hoga)
            for (int p = 2; (long long)p * p <= n; p++) {
                
                // Agar p, n ko fully divide kar deta hai, matlab p ek prime factor hai
                if (n % p == 0) {
                    
                    // num ko prime 'p' ke saath connect (union) kar do
                    // Prime p ko represent kar rahe hain index (max_num + p) se (offset trick)
                    // Isse: agar koi doosra number bhi prime p se divisible hai, 
                    // to wo automatically isi component me aa jayega (kyunki dono p se jude hain)
                    uf.UNION_BY_RANK(num, max_num + p);
                    
                    // n se prime p ke saare occurrences nikaal do
                    // Example: agar n = 12 = 2*2*3, to p=2 milne par,
                    // hum n ko 2 baar divide karenge: 12 -> 6 -> 3
                    // (taaki wahi prime dobara process na ho, aur n chhota hota jaye)
                    while (n % p == 0) {
                        n /= p;
                    }
                }
            }
            
            // Loop khatam hone ke baad, agar n abhi bhi 1 se bada hai,
            // matlab n khud ek prime number hai (woh last bacha hua factor)
            // Example: num = 13 (prime hai), loop chalega hi nahi (p*p > 13 jaldi),
            // to n = 13 hi rahega, aur yahan handle ho jayega
            if (n > 1) {
                // num ko is bache hue prime factor ke saath bhi union kar do
                uf.UNION_BY_RANK(num, max_num + n);
            }
        }
        // ↑ Ab tak: jo bhi numbers common prime factors share karte hain (directly ya 
        //   indirectly chain ke through), wo sab ek hi connected component me aa gaye hain
        
        // STEP 4: Original array ki sorted copy banao
        // Yeh wahi "target" arrangement hai jo humein achieve karna hai agar sort possible hai
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        // STEP 5: Har position pe check karo ki kya woh sahi tarah se sort ho sakti hai
        for (int i = 0; i < (int)nums.size(); i++) {
            
            // Agar is index pe original aur sorted value already same hai,
            // to is position ke liye koi swap chahiye hi nahi — yeh already correct hai
            // (isliye if block ke andar hi check karte hain, taaki unnecessary find() calls bachen)
            if (nums[i] != sorted_nums[i]) {
                
                // Values different hain — matlab is position ke number ko
                // "move" karna padega taaki sorted value yahan aa sake
                //
                // Yeh sirf tabhi possible hai jab nums[i] aur sorted_nums[i]
                // dono SAME connected component me ho (kyunki ek component ke
                // andar hum free reordering kar sakte hain via swaps)
                if (uf.find(nums[i]) != uf.find(sorted_nums[i])) {
                    
                    // Roots alag hain, matlab yeh do numbers kabhi connect nahi ho sakte
                    // (unka koi common prime factor chain nahi hai)
                    // Isliye is position ko sahi value nahi mil sakti — array sort nahi ho sakta
                    return false;
                }
                // Agar roots same hain, to yeh position theek hai (aage check karte hain)
            }
        }
        
        // STEP 6: Agar saari positions pass ho gayi (koi bhi false nahi mila),
        // matlab har jagah sahi value tak "pahunchna" possible hai swaps se
        // Isliye array ko sort karna possible hai
        return true;
    }
};