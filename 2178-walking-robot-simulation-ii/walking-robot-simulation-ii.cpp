class Robot {
public:
    int w, h;
    int x, y;
    int dir; // 0=North, 1=East, 2=South, 3=West

    vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 1; // initally East se shru krega robot 
    }

    void step(int num) {
        int cycle = 2 * (w + h) - 4; // kitni cycles complete krga robot
        num %= cycle;

        if (num == 0) num = cycle;

        while (num--) {
            int nx = x + directions[dir].first;
            int ny = y + directions[dir].second;

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 3) % 4; // LEFT
                nx = x + directions[dir].first;
                ny = y + directions[dir].second;
            }

            x = nx;
            y = ny;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 0) return "North";
        if (dir == 1) return "East";
        if (dir == 2) return "South";
        return "West";
    }
};