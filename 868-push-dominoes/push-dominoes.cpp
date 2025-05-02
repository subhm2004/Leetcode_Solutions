class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);

        // 'R' ka effect (Left to Right loop)
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R')
                force = n; // Full rightward force start
            else if (dominoes[i] == 'L')
                force = 0; // Left block kar deta hai, force khatam
            else
                force = max(force - 1, 0); // R se door jaane par force kam hota hai
            forces[i] += force;
        }

        // 'L' ka effect (Right to Left loop)
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L')
                force = n; // Full leftward force start
            else if (dominoes[i] == 'R')
                force = 0; // R block karta hai left force ko
            else
                force = max(force - 1, 0); // L se door jaane pe force kam
            forces[i] -= force; // L ka force negative hota hai
        }

        // Final ans Banao
        string ans;
        for (int i = 0; i < forces.size(); i++) {
            if (forces[i] > 0) {
                ans += 'R';
            } else if (forces[i] < 0) {
                ans += 'L';
            } else {
                ans += '.';
            }
        }

        return ans;
    }
};
