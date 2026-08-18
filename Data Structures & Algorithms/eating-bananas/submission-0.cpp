class Solution {
public:
    bool check(vector<int>& piles, int k, int h) {
        int totalHour = 0;
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
        int maxPile = piles[0];
        for (int i = 1; i < n; i++) {
            maxPile = max(maxPile, piles[i]);
        }
        
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
