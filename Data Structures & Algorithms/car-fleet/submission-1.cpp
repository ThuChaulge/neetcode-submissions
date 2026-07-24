class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> car;
        car.reserve(n);
        int max_time = 0;
        for (int i = 0; i < n; i++) {
            car.push_back({position[i], speed[i]});
        }
        int result = 0;
        sort(car.begin(), car.end());
        vector<int> stack;
        for (int i = n-1; i >= 0; i--) {
            int t = (target - car[i].first)*100/car[i].second;
            if (t > max_time) {
                max_time = t;
                result++;
            } 
        }
        return result;
    }
};
