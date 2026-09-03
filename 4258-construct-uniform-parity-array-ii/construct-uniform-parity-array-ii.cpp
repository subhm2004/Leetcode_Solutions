class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        // Sabse chhota odd number store karenge.
        // Initially INT_MAX rakha hai taaki koi bhi odd number
        // milte hi minOdd update ho sake.
        int minOdd = INT_MAX;

        // Sabse chhota even number store karenge.
        int minEven = INT_MAX;

        // Puri array traverse karenge.
        for (int x : nums1) {

            // Agar x even hai
            if (x % 2 == 0) {

                // Sabse chhota even number find kar rahe hain.
                minEven = min(minEven, x);

            } else {

                // Agar x odd hai,
                // toh sabse chhota odd number find kar rahe hain.
                minOdd = min(minOdd, x);
            }
        }

        /*
            CASE 1: Array mein koi odd number hi nahi hai.

            Example:
            nums1 = [2, 4, 6]

            Saare numbers already even hain,
            isliye hum nums2 = nums1 choose kar sakte hain.

            Therefore answer = true.
        */
        if (minOdd == INT_MAX) {
            return true;
        }

        /*
            Yahan array mein kam se kam ek odd number hai.

            All EVEN banana possible nahi hai.

            Kyon?

            Maan lo smallest odd number = minOdd.

            Is odd number ko even banane ke liye
            kisi ODD number ko subtract karna padega:

                Odd - Odd = Even

            Lekin minOdd sabse chhota odd number hai.
            Isse chhota koi odd number available nahi hai.

            Aur hum khud ko subtract nahi kar sakte (j != i).

            Isliye agar odd numbers present hain,
            toh hume ALL ODD banane ki koshish karni padegi.

            Kisi EVEN number ko ODD banane ke liye:

                Even - Odd = Odd

            Hume har even number se koi smaller odd number
            subtract karna hoga.

            Sabse useful odd number obviously smallest odd number hai.

            Agar:

                minOdd < minEven

            toh minOdd har even number se chhota hoga.

            Isliye har even number ke liye:

                even - minOdd

            positive hoga aur ODD hoga.

            Example:

                nums1 = [1, 4, 7]

                minOdd  = 1
                minEven = 4

                1 < 4 → TRUE

                1       → odd
                4 - 1   = 3 → odd
                7       → odd

                nums2 = [1, 3, 7]

                All odd → TRUE
        */

        return minOdd < minEven;
    }
};