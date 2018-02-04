// Time: O(n), Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = -prices[0], sell = 0, cooldown = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int temp = cooldown;
            cooldown = max(cooldown, sell);
            sell = buy + prices[i];
            buy = max(buy, temp - prices[i]);
        }
        return max(sell, cooldown);
    }
};