class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0;   
        int prevEnd = 0;    

        // Meetings ko unke start time ke hisaab se sort karo
        sort(meetings.begin(), meetings.end());

        // Har meeting ko process karo
        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];  // Current meeting ka start aur end time

            // Agar current meeting aur previous meeting ke beech gap hai, toh free days calculate karo
            if (start > prevEnd) {
                freeDays += start - prevEnd - 1;   // Gap ke andar kitne free days hain
            }

            // Previous end time ko update karo, taki overlapping meetings ko handle kar sake
            prevEnd = max(prevEnd, end);
        }

        // Last meeting ke baad jo free days bache hain, unhe add karo
        return freeDays + max(0, days - prevEnd);  // Agar last meeting ke baad free days hain, toh unhe add karo
    }
};
