class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        // Sabhi players ko skill ke increasing order mein sort kar do
        sort(skill.begin(), skill.end());

        int n = skill.size();

        /*
            Sabse chhote aur sabse bade player ko pair karenge.

            In dono ka sum hi har team ka required sum hoga.

            Example:
            [1,2,3,3,4,5]

            target = 1 + 5 = 6
        */
        int target = skill[0] + skill[n - 1];

        // Sabhi teams ki chemistry ka total
        long long ans = 0;

        // Two pointers
        int left = 0;
        int right = n - 1;

        /*
            Jab tak players bach rahe hain,
            smallest aur largest ko pair karte jao.
        */
        while (left < right) {

            /*
                Current pair ka total skill
                target ke equal hona chahiye.

                Agar equal nahi hai,
                toh valid teams banana possible nahi hai.
            */
            if (skill[left] + skill[right] != target) {
                return -1;
            }

            /*
                Current team ki chemistry:

                    skill[left] * skill[right]
            */
            ans += 1LL * skill[left] * skill[right];

            // Dono players ab use ho gaye
            left++;
            right--;
        }

        return ans;
    }
};