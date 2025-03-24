class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;  // Vector to store valid scores

        // Har operation ko process karo
        for (const string& operation : operations) {
            if (operation == "+") {
                // Last do scores ka sum add karo
                int lastTwoSum = scores[scores.size() - 1] + scores[scores.size() - 2];
                scores.push_back(lastTwoSum);  // Sum ko list mein daal do
            } else if (operation == "D") {
                // Last score ko double karo aur list mein add karo
                int doubleLast = scores[scores.size() - 1] * 2;
                scores.push_back(doubleLast);  // Doubled score ko add karo
            } else if (operation == "C") {
                // Last score ko remove karo
                scores.pop_back();  // Last element ko pop karo
            } else {
                // String ko integer mein convert karo aur list mein add karo
                scores.push_back(stoi(operation));  // Score ko list mein daal do
            }
        }

        // Sabhi scores ka sum calculate karo aur return karo
        return accumulate(scores.begin(), scores.end(), 0);  // Sum return karo
    }
};
