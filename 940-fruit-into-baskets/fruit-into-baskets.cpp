class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, left = 0;
        unordered_map<int, int>
            count; // Har fruit ka count store karne ke liye map

        for (int right = 0; right < fruits.size(); ++right) {
            count[fruits[right]]++; // Naya fruit add karo ya count badhao

            while (count.size() > 2) { // Agar 2 se zyada alag type ke fruits ho
                                       // gaye toh window chhoti karo
                if (--count[fruits[left]] == 0)
                    count.erase(fruits[left]); // Agar kisi fruit ka count 0 ho
                                               // gaya toh use hata do
                left++;                        // Window ka left side badhao
            }

            ans = max(ans, right - left + 1); // Maximum window size update karo
        }
        return ans;
    }
};
