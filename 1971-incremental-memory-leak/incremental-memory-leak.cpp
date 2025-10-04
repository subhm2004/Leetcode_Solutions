class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int sec = 1;
        while (true) {
            // Agar dono sticks me required memory nahi hai → crash
            if (memory1 < sec && memory2 < sec) break;
            
            // Jis stick me zyada memory hai → usse allocate
            if (memory1 >= memory2) memory1 -= sec;
            else memory2 -= sec;
            
            sec++; // agla sec
        }
        
        return {sec, memory1, memory2};
    }
};
