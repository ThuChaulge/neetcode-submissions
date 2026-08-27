class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const auto& arrayOfValue = mp[key];
        int size = arrayOfValue.size();
        if (size == 0) {
            return "";
        } else {
            string ans = "";
            int low = 0, high = size-1;
            
            while (low <= high) {
                int mid = low + (high - low)/2;
                if (arrayOfValue[mid].first <= timestamp) {
                    ans = arrayOfValue[mid].second;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return ans;
        }
        
    }
};
