class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> car;
        car.reserve(n);
        
        for (int i = 0; i < n; i++) {
            car.push_back({position[i], speed[i]});
        }

        sort(car.begin(), car.end());
        vector<double> s;
        for (int i = n-1; i >= 0; i--) {
            double t = (double)(target - car[i].first)/car[i].second;
            s.push_back(t);
            if (s.size() >= 2 && s[s.size()-2] >= s.back()) {
                s.pop_back();
            }
        }
        return s.size();
    }
};
