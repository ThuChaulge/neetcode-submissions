class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > minPrice) {
                result = max(result, prices[i] - minPrice);
            } else {
                minPrice = min(minPrice, prices[i]);
            }
        }
        return result;
    }
};
