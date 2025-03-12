class Solution {
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int count0 = 0, count1 = 0;

    // Count the number of students preferring each type of sandwich
    for (int student : students) {
      if (student == 0)
        count0++;
      else
        count1++;
    }

    // Serve sandwiches one by one
    for (int sandwich : sandwiches) {
      if (sandwich == 0 && count0 > 0)
        count0--;
      else if (sandwich == 1 && count1 > 0)
        count1--;
      else
        break; // Remaining students can't eat
    }

    return count0 + count1; // Students left without sandwiches
  }
};
