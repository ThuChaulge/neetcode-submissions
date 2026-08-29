class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int result = 0;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                result = max(result, prices[r] - prices[l]);
            } else {
                l = r;
            }
            r++;
        }
        return result;
    }
};
