class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& arr) {
        int m = arr.size();

        sort(begin(arr), end(arr)); // Meetings ko start time ke hisaab se sort kar diya

        vector<int> rooms_Used_Count(n, 0); // Har room kitni baar use hua hai track karne ke liye
        vector<long long> last_available_at(n, 0); // Har room last kab free hoga uska time

        // Har meeting ke liye ek ek karke dekhenge
        for (vector<int>& meet : arr) {
            int start = meet[0];
            int end = meet[1];
            bool found = false; // Yeh batayega koi room mila ya nahi

            long long Early_End_Room_Time = LLONG_MAX; // Sabse jaldi available room ka time
            int Early_End_Room_ = 0; // Sabse jaldi available room ka index

            // Har room check karo
            for (int room = 0; room < n; room++) {
                if (last_available_at[room] <= start) {
                    // Agar yeh room start time tak free ho gaya to isi room mein meeting karwa do
                    found = true;
                    last_available_at[room] = end; // Room ab end tak busy hai
                    rooms_Used_Count[room]++; // Room use count badhao
                    break;
                }

                // Agar koi bhi room free nahi mila, to sabse jaldi free hone wale room ko yaad rakho
                if (last_available_at[room] < Early_End_Room_Time) {
                    Early_End_Room_ = room;
                    Early_End_Room_Time = last_available_at[room];
                }
            }

            if (!found) {
                // Koi room free nahi mila, to sabse jaldi free hone wale room mein meeting delay karke karwao
                last_available_at[Early_End_Room_] += (end - start);
                rooms_Used_Count[Early_End_Room_]++;
            }
        }

        // Ab humein sabse zyada baar use hone wala room find karna hai
        int ans = 0;
        int max_use = 0;
        for (int room = 0; room < n; room++) {
            if (rooms_Used_Count[room] > max_use) {
                max_use = rooms_Used_Count[room];
                ans = room;
            }
        }

        return ans; // Sabse zyada baar use hone wala room ka number return karo
    }
};
