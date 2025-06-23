class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int w = sqrt(area); w >= 1; --w) {
            if (area % w == 0) {
                int l = area / w;
                return {l, w};  
            }
        }
        return {};   
    }
};

/*
| Condition            | Where Satisfied                             | How                 |
| -------------------- | ------------------------------------------- | ------------------- |
| `L * W == area`      | `if (area % w == 0)`                        | Valid divisors only |
| `L >= W`             | Since `w ≤ sqrt(area) ⇒ l ≥ w`              | So L ≥ W            |
| `L - W` is minimized | First valid pair found from `sqrt → 1` loop | Smallest difference |
*/