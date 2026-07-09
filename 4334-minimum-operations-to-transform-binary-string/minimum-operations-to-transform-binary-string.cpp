class Solution {
public:
    int minOperations(string s1, string s2) {

        int n = s1.size();

        // Total minimum operations store karega
        int ans = 0;

        // Left se right tak har character process karenge
        for (int i = 0; i < n; i++) {

            // -------------------------------------------------
            // Case 1:
            // Agar current character already target ke equal hai,
            // to kuch karne ki zarurat nahi.
            // -------------------------------------------------
            if (s1[i] == s2[i])
                continue;

            // =================================================
            // Case 2:
            // Current character 0 hai aur target 1 hai.
            //
            // Sirf ek hi operation possible hai:
            //      0 -> 1
            // =================================================
            if (s1[i] == '0') {

                // Character ko 1 bana do
                s1[i] = '1';

                // Ek operation use hua
                ans++;

                continue;
            }

            // =================================================
            // Ab yahan sirf ek hi possibility bachi:
            //
            // s1[i] = '1'
            // s2[i] = '0'
            //
            // Direct 1 -> 0 operation exist nahi karta.
            //
            // Hume "11 -> 00" operation use karna padega.
            // =================================================


            // =================================================
            // Case 3:
            // Right neighbour already 1 hai.
            //
            // Example:
            //      11
            //   -> 00
            //
            // Bas ek operation me dono 0 ban jayenge.
            // =================================================
            if (i + 1 < n && s1[i + 1] == '1') {

                s1[i] = '0';
                s1[i + 1] = '0';

                ans++;

                continue;
            }


            // =================================================
            // Case 4:
            // Right me 1 nahi mila.
            //
            // Check karo left me 1 hai ya nahi.
            //
            // Example:
            //
            //      110
            //       ^
            //
            // Left wale 1 ke saath pair bana sakte hain.
            //
            //      11 -> 00
            //
            // Lekin agar target me left wala character 1 hona
            // chahiye tha to usko dobara 1 banana padega.
            // =================================================
            if (i - 1 >= 0 && s1[i - 1] == '1') {

                // Current position target ke equal kar do
                s1[i] = s2[i];

                // Pair operation
                ans++;

                // Agar target me left character 1 hai,
                // to usko restore karna padega.
                if (s2[i - 1] == '1')
                    ans++;

                // Left neighbour ko target ke equal kar diya.
                s1[i - 1] = s2[i - 1];

                continue;
            }


            // =================================================
            // Case 5:
            // Right neighbour 0 hai.
            //
            // Pair operation ke liye pehle usko 1 banana padega.
            //
            // Example:
            //
            //      10
            //
            // Step1 : 10 -> 11
            //
            // Step2 : 11 -> 00
            //
            // Agar target me right character 1 hona chahiye,
            // to usko baad me restore bhi karenge.
            // =================================================
            if (i + 1 < n && s1[i + 1] == '0') {

                // Current character target ke equal ho gaya
                s1[i] = s2[i];

                // 2 operations:
                // 0->1
                // 11->00
                ans += 2;

                // Agar target me right character 1 hai,
                // to ek aur operation lagega restore karne ke liye.
                if (s2[i + 1] == '1')
                    ans++;

                // Right neighbour ko target ke equal kar diya.
                s1[i + 1] = s2[i + 1];

                continue;
            }


            // =================================================
            // Case 6:
            // Right side possible nahi tha.
            //
            // Ab left side try karte hain.
            //
            // Example:
            //
            //      01
            //       ^
            //
            // Left ko pehle 1 banayenge.
            //
            //      01 -> 11
            //
            // Fir
            //
            //      11 -> 00
            //
            // Fir agar target me left 1 tha,
            // to usko restore karenge.
            // =================================================
            if (i - 1 >= 0 && s1[i - 1] == '0') {

                s1[i] = s2[i];

                ans += 2;

                if (s2[i - 1] == '1')
                    ans++;

                s1[i - 1] = s2[i - 1];

                continue;
            }


            // =================================================
            // Agar koi bhi operation possible nahi hua,
            // to transformation impossible hai.
            // =================================================
            return -1;
        }

        // Final verification
        // Agar poori string target ban gayi,
        // to answer return karo.
        // Warna impossible.
        if (s1 == s2)
            return ans;

        return -1;
    }
};