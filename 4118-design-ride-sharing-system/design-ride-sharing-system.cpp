class RideSharingSystem {
public:
    queue<int> riders;
    queue<int> drivers;

    unordered_set<int> riders_waiting;    

    RideSharingSystem() {
    }

    void addRider(int riderId) {
        riders.push(riderId);
        riders_waiting.insert(riderId);
    }

    void addDriver(int driverId) {
        drivers.push(driverId);
    }

    vector<int> matchDriverWithRider() {

        // remove cancelled riders from front
        while (!riders.empty() && riders_waiting.count(riders.front()) == 0) {
            riders.pop();
        }

        if (drivers.empty() || riders.empty())
            return {-1, -1};

        int driver = drivers.front(); drivers.pop();
        int rider  = riders.front();  riders.pop();

        riders_waiting.erase(rider);   // matched

        return {driver, rider};
    }

    void cancelRider(int riderId) {
        if (riders_waiting.count(riderId)) {
            riders_waiting.erase(riderId);
        }
    }
};


/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */