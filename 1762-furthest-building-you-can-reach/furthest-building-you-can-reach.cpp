class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    // Min-heap banaya hai taaki chhoti climb ko easily track kar sakein
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 1; i < heights.size(); ++i) {
      int climb = heights[i] - heights[i - 1];

      // Agar agla building neeche ya same height pe hai toh seedha chalo
      if (climb <= 0) continue;

      // Har positive climb ko heap mein daal rahe hain
      minHeap.push(climb);

      // Agar ladders se zyada climb ho gayi hai,
      // toh sabse chhoti climb ke liye bricks use karo
      if (minHeap.size() > ladders) {
        bricks -= minHeap.top();  // bricks use kar rahe hain
        minHeap.pop();            // us climb ko hata diya heap se
      }

      // Agar bricks khatam ho gaye toh aage nahi ja sakte
      if (bricks < 0)
        return i - 1;
    }

    // Agar loop pura chal gaya, toh last building tak pahuch gaye
    return heights.size() - 1;
  }
};
