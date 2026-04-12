// Law of Cosines (Cosine Rule)
// angle = acos(value) * 180.0 / M_PI
// acos return krta h value radian me to degree me convert krne k liye 180.0 /
// M_PI se multiply
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        vector<double> ans;

        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        if (a + b <= c || a + c <= b || b + c <= a) {
            return {};
        }

        double angle_A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / M_PI;
        double angle_B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180.0 / M_PI;
        double angle_C = 180.0 - angle_A - angle_B;

        ans.push_back(angle_A);
        ans.push_back(angle_B);
        ans.push_back(angle_C);

        sort(ans.begin(),ans.end());

        return ans;
    }
};