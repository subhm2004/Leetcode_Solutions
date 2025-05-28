class Solution {
public:
    int minTimeToType(string word) {
        char current = 'a'; 
        int time = 0;

        for (char c : word) {
            int moveTime = min(abs(current - c), 26 - abs(current - c));
            time += moveTime + 1; // move + type
            current = c;
        }

        return time;
    }
};
