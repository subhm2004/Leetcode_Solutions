class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while (left < n && s[left] == 'L') 
            left++;

        while (right >= 0 && s[right] == 'R') 
            right--;

        int collisions = 0;

         for (int i = left; i <= right; i++) {
            if (s[i] != 'S')
                collisions++;
        }

        return collisions;
    }
};
