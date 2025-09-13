class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;  // original perm ka size (n is odd)

        // Step 1: total_XOR = 1 XOR 2 XOR ... XOR n
        int total_XOR = 0;
        for (int i = 1; i <= n; i++) {
            total_XOR ^= i;
        }

        // Step 2: odd_XOR = encoded[1] XOR encoded[3] XOR ...
        int odd_XOR = 0;
        for (int i = 1; i < encoded.size(); i += 2) {
            odd_XOR ^= encoded[i];
        }

        // Step 3: First element find karo
        int first = total_XOR ^ odd_XOR;

        // Step 4: Ab pura array bana lo
        vector<int> perm(n);
        perm[0] = first;
        for (int i = 0; i < encoded.size(); i++) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }

        return perm;
    }
};

