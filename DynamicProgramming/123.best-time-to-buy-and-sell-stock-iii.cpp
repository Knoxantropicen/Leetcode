// Time: O(n), Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int firstBuy = -prices[0], firstSell = 0, secondBuy = INT_MIN, secondSell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            secondSell = max(secondBuy + prices[i], secondSell);
            secondBuy = max(firstSell - prices[i], secondBuy);
            firstSell = max(firstBuy + prices[i], firstSell);
            firstBuy = max(-prices[i], firstBuy);
        }
        return max(firstSell, secondSell);
    }