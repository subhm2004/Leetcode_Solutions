using ll = long long;
class Solution {
public:

    bool is_possible(ll mid, vector<int>& d, vector<int>& r) {

        ll lcm = (1LL * r[0] * r[1]) / __gcd(r[0], r[1]);

        // Sirf Drone1 hi delivery kar sakta hai
        ll onlyDrone1 = mid / r[1] - mid / lcm;

        // Sirf Drone2 hi delivery kar sakta hai
        ll onlyDrone2 = mid / r[0] - mid / lcm;

        // Dono drones free hain
        ll bothFree = mid - mid / r[0] - mid / r[1] + mid / lcm;

        // Exclusive hours dene ke baad kitni deliveries bach gayi
        ll remainingDrone1 = max(0LL, (ll)d[0] - onlyDrone1);
        ll remainingDrone2 = max(0LL, (ll)d[1] - onlyDrone2);

        // Kya common free hours me adjust ho jayengi?
        return (remainingDrone1 + remainingDrone2 <= bothFree);
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {

        ll low = 1;
        ll high = 4e10;
        ll ans = high;

        while (low <= high) {

            ll mid = low + (high - low) / 2;

            if (is_possible(mid, d, r)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};