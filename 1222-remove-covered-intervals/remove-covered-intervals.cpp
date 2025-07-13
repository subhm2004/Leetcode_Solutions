class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        // STEP 1: SORTING LOGIC
        // Pehle intervals ko sort karte hain ek special way mein:
        // - Start point ke basis par ascending order mein (chota pehle)
        // - Agar start point same hai, to end point ke basis par descending order mein (bada pehle)
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1]; // start same hai to bada end pehle aaye
            return a[0] < b[0];     // start chota hai to pehle aaye
        });
        
        // STEP 2: COUNTING NON-COVERED INTERVALS
        int count = 0;      // kitne intervals covered nahi hain
        int max_end = 0;    // ab tak ka maximum end point
        
        // Har interval ko check karte hain
        for (auto& interval : intervals) {
            int curr_end = interval[1];  // current interval ka end point
            
            // Agar current interval ka end point max_end se bada hai
            // matlab ye interval kisi se covered nahi hai
            if (curr_end > max_end) {
                count++;                 // count badhao
                max_end = curr_end;      // max_end update karo
            }
            // Agar curr_end <= max_end hai, matlab ye interval covered hai
            // to ise skip kar dete hain (kuch nahi karte)
        }
        
        return count;  // final answer return karo
    }
};

/*
=== DRY RUN EXAMPLE ===
Input: intervals = [[1,4], [3,6], [2,8]]

STEP 1: SORTING
Original: [[1,4], [3,6], [2,8]]
After sorting by start (and end descending if start same):
[[1,4], [2,8], [3,6]]

STEP 2: PROCESSING
count = 0, max_end = 0

Iteration 1: interval = [1,4]
- curr_end = 4
- curr_end (4) > max_end (0)? YES
- count = 1, max_end = 4
- [1,4] is NOT covered

Iteration 2: interval = [2,8]  
- curr_end = 8
- curr_end (8) > max_end (4)? YES
- count = 2, max_end = 8
- [2,8] is NOT covered

Iteration 3: interval = [3,6]
- curr_end = 6  
- curr_end (6) > max_end (8)? NO
- count remains 2
- [3,6] is COVERED by [2,8] (because 2 <= 3 and 6 <= 8)

Final Answer: 2

=== WHY THIS WORKS ===

1. SORTING LOGIC:
   - Start ke basis par sort karne se hum guarantee kar sakte hain ki
     agar koi interval [a,b] hai, to usse pehle wale sab intervals ka
     start <= a hoga
   
   - Same start wale intervals mein bada end pehle rakhne se hum ensure
     karte hain ki chota end wala interval automatically covered ho jayega

2. GREEDY APPROACH:
   - max_end track karte hain jo ab tak ka maximum end point hai
   - Agar current interval ka end max_end se bada hai, matlab ye
     covered nahi hai kyunki koi previous interval ise completely contain
     nahi kar sakta
   
   - Agar current interval ka end <= max_end hai, matlab ye interval
     pehle se covered hai kisi bade interval se

3. COVERED INTERVAL KA DEFINITION:
   - Interval [a,b] is covered by [c,d] if c <= a and b <= d
   - Sorting ke baad c <= a already guaranteed hai
   - Bas b <= d check karna hai, jo hum max_end se kar rahe hain

Time Complexity: O(n log n) - sorting ke liye
Space Complexity: O(1) - extra space nahi use kar rahe
*/