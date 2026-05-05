class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume = 1LL * length * width * height;

        bool isBulky = (length >= 1e4 || width >= 1e4 || height >= 1e4 || volume >= 1e9);
        bool isHeavy = (mass >= 100);

        if (isBulky && isHeavy)
            return "Both";
        if (isBulky)
            return "Bulky";
        if (isHeavy)
            return "Heavy";
        return "Neither";
    }
};