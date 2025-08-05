class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0.0;
        int prev_upper = 0;

        for (const auto& bracket : brackets) {
            int upper = bracket[0];
            int percent = bracket[1];

            if (income <= prev_upper) break;

            int taxabe_income = min(income, upper) - prev_upper;
            tax += (taxabe_income * percent) / 100.0;

            prev_upper = upper;
        }

        return tax;
    }
};
