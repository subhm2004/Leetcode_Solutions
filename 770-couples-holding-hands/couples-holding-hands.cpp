class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();

        // har person kis index pe baitha hai
        vector<int> position(n);

        for (int i = 0; i < n; i++) {
            position[row[i]] = i;
        }

        int swaps = 0;

        // har pair check karenge
        for (int i = 0; i < n; i += 2) {

            int first_person = row[i];

            // partner nikalna
            int partner = first_person ^ 1;

            // agar already saath baithe hain
            if (row[i + 1] == partner) {
                continue;
            }

            // partner kaha baitha hai
            int partner_idx = position[partner];

            // current wrong person
            int current_wrong_person = row[i + 1];

            // swap
            swap(row[i + 1], row[partner_idx]);

            // positions update karo
            position[current_wrong_person] = partner_idx;
            position[partner] = i + 1;

            swaps++;
        }

        return swaps;
    }
};