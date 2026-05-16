class Solution {
public:

    int distMoney(int money, int children) {

        // sabko 1 dollar dena zaroori
        if(money < children) {
            return -1;
        }

        money -= children;

        // kitne children ko extra 7 deke 8 bana sakte hain
        int eight_Dollar_Children = min(money / 7, children);

        money -= eight_Dollar_Children * 7;
        children -= eight_Dollar_Children;

        // agar sab children ko 8 diye aur fir bhi paise bach gaye
        if(children == 0 && money > 0) {
            return eight_Dollar_Children - 1;
        }

        // agar ek child bacha aur uske paas total 4 dollars ban rahe hain
        if(children == 1 && money == 3) {
            return eight_Dollar_Children - 1;
        }

        return eight_Dollar_Children;
    }
};