class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Step 1: Trips ko unke start time ke basis pe sort kar lo
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // start time compare kar rahe hain
        });

        // Min-heap banate hain jo har active trip ka {end_time, passengers} store karega
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        int currentPassengers = 0;

        // Step 2: Har trip ko process karo
        for (auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            // Step 3: Jo trips already khatam ho chuki hain unhe heap se hata do
            while (!minHeap.empty() && minHeap.top().first <= start) {
                currentPassengers -= minHeap.top().second; // utarne wale passengers hatao
                minHeap.pop();
            }

            // Step 4: Current trip ko heap me add karo
            minHeap.emplace(end, passengers);
            currentPassengers += passengers;

            // Step 5: Agar capacity exceed ho gayi to return false
            if (currentPassengers > capacity)
                return false;
        }

        // Agar koi bhi trip capacity ko exceed nahi karti to return true
        return true;
    }
};
