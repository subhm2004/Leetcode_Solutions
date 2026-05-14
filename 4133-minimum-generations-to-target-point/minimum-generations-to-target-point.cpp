class Solution {
public:

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        set<vector<int>> visited;

        vector<vector<int>> all_points;

        // generation 0
        for(auto &p : points) {

            if(p == target) {
                return 0;
            }

            visited.insert(p);
            all_points.push_back(p);
        }

        int generation = 0;

        while(true) {

            generation++;

            vector<vector<int>> new_points;

            int n = all_points.size();

            // use all available points
            for(int i = 0; i < n; i++) {

                for(int j = i + 1; j < n; j++) {

                    vector<int> a = all_points[i];
                    vector<int> b = all_points[j];

                    vector<int> c = {
                        (a[0] + b[0]) / 2,
                        (a[1] + b[1]) / 2,
                        (a[2] + b[2]) / 2
                    };

                    // target found
                    if(c == target) {
                        return generation;
                    }

                    // if new point
                    if(!visited.count(c)) {

                        visited.insert(c);

                        new_points.push_back(c);
                    }
                }
            }

            // no new points possible
            if(new_points.empty()) {
                return -1;
            }

            // add newly generated points
            for(auto &p : new_points) {
                all_points.push_back(p);
            }
        }

        return -1;
    }
};