class Solution {
public:
    bool check(const vector<int>& piles, int k, int h) {
        long long totalHour = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHour += (piles[i] + k - 1)/k;
            if (totalHour > h) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = *max_element(piles.begin(), piles.end());
        
        int low = 1;
        int high = maxPile;
        int result = 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (check(piles, mid, h) == false) {
                low = mid + 1;
            } else {
                result = mid;
                high = mid - 1;
            }
        }
        return result;
    }
};
