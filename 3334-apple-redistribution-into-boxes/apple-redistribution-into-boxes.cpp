class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        // Capacity ko descending order me sort karo
        sort(capacity.begin(), capacity.end(), greater<int>());

        // Total apples ka sum nikaalo
        int totalApple = accumulate(apple.begin(), apple.end(), 0);

        int count = 0;

        // Jab tak apples khatam na ho jaaye
        for (int i = 0; i < capacity.size() && totalApple > 0; i++) {
            totalApple -= capacity[i]; // current box me apples daalo
            count++;                   // ek box use hua
        }

        return count;  
    }
};
