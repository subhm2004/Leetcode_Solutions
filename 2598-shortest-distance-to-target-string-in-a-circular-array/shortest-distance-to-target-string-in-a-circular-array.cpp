class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start_idx) {
        int n = words.size();

        // Dono directions mein target search karte h 
        for (int i = 0; i < n; i++) {
            // closewise move: (start_idx + i) % n
            int right = (start_idx + i) % n;
            
            // anti-closewise move: (start_idx - i + n) % n
            int left = (start_idx - i + n) % n;

            // Agar target kisi direction mein mil jaaye, to i steps return karo
            if (words[right] == target || words[left] == target)
                return i;
        }

        // Agar target nahi milta, to -1 return kr dege
        return -1;
    }
};
