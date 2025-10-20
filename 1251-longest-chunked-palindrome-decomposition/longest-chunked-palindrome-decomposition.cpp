// Recursive mirror split problem bhi bolte hai ise
// Variable window hai (to hum window ko slide nhi kr skte kyoki fixed size nhi hai to window me koi bhi values subtract nhi hogi )to dynamic rolling hash ka use hoga left hash or right hash likhne padenge to hash_pair function nhi likhna mltb ki bas window me values add hogi 
typedef long long ll;
class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        
        // Double hashing ke liye do alag moduli aur RADIX values
        ll MOD_1 = 1e9+7;
        ll MOD_2 = 1e9+33;
        ll RADIX_1 = 26;
        ll RADIX_2 = 27;

        ll left_hash1 = 0, right_hash1 = 0;
        ll left_hash2 = 0, right_hash2 = 0;
        ll power_1 = 1, power_2 = 1;
        
        int count = 0;

        for (int i = 0; i < n; i++) {
            /** 
             * Left hash formula:
             * left_hash = text[0]*RADIX^i + text[1]*RADIX^(i-1) + ... + text[i]*RADIX^0  (mod MOD)
             * 
             * Hum left se rolling hash calculate karte hain.
             * Har step me purana hash RADIX se multiply karke new character add karte hain.
             */
            left_hash1 = (left_hash1 * RADIX_1 + text[i]) % MOD_1;
            left_hash2 = (left_hash2 * RADIX_2 + text[i]) % MOD_2;

            /**
             * Right hash formula:
             * right_hash = text[n-1]*RADIX^0 + text[n-2]*RADIX^1 + ... + text[n-1-i]*RADIX^i  (mod MOD)
             *
             * Hum right se rolling hash calculate karte hain.
             * Yahan har character ke liye explicit 'power' variable ka use hota hai
             * taaki left hash ke corresponding powers se align ho jaye aur mirror check possible ho.
             */
            right_hash1 = (right_hash1 + power_1 * text[n - 1 - i]) % MOD_1;
            right_hash2 = (right_hash2 + power_2 * text[n - 1 - i]) % MOD_2;

            // Next step ke liye powers update kar rahe hain (sirf right hash ke liye)
            power_1 = (power_1 * RADIX_1) % MOD_1;
            power_2 = (power_2 * RADIX_2) % MOD_2;

            /**
             * Agar dono hashes match kar gaye → ek mirror segment mil gaya
             * Mirror segment ka matlab: 
             * left substring [0..i] == right substring [n-1-i..n-1]
             */
            if (left_hash1 == right_hash1 && left_hash2 == right_hash2) {
                count++;
                // Next segment ke liye hashes aur powers reset kar rahe hain
                left_hash1 = left_hash2 = 0;
                right_hash1 = right_hash2 = 0;
                power_1 = power_2 = 1;
            }
        }

        return count;
    }
};
