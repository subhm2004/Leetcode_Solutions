class ParkingSystem {
private:
    vector<int> slots;

public:
    ParkingSystem(int big, int medium, int small) {
        slots = {big, medium, small};
    }
    
    bool addCar(int carType) {
        int idx = carType - 1; // 1->0, 2->1, 3->2 0    based index me convert kar diya 
        if (slots[idx] > 0) {
            slots[idx]--;
            return true;
        }
        return false;
    }
};
