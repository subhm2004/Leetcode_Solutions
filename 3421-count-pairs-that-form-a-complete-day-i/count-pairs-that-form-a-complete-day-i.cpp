class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        vector<int> freq(24, 0); // Har remainder (0 to 23) ka count rakhne ke liye array

        int count = 0; // Total valid pairs ka count

        for (int h : hours) {
            int rem = h % 24; // Current hour ka 24 ke saath remainder nikalo

            // Agar remainder 0 hai, toh hume aur bhi 0 remainder wale chahiye
            // Kyunki 0 + 0 = 0 (which is divisible by 24)
            if (rem == 0)
                count += freq[0]; 
            else
                count += freq[24 - rem]; // Nahi toh 24 - rem wala remainder chahiye hoga

            // Ab current remainder ka count badha do future ke pairs ke liye
            freq[rem]++;
        }

        return count; // Total pairs return karo
    }
};
