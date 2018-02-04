// Time: O(n*k), Space: O(k) if k >= ceil(n/2) else Time: O(n), Space: O(1)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        if (k >= int((prices.size() + 1) / 2)) {    // any transaction times
            int n = prices.size();
            int buyTime = 0, maxPro = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] < prices[i - 1]) {
                    maxPro += prices[i - 1] - prices[buyTime];
                    buyTime = i;
                }
            }
            return maxPro + max(prices[n - 1] - prices[buyTime], 0);
        } else {    // limited transaction times
            vector<int> buy(k, INT_MIN), sell(k, 0);
            buy[0] = -prices[0];
            int maxSell = 0;
            for (int i = 1; i < prices.size(); ++i) {
                for (int j = k - 1; j >= 0; --j) {
                    sell[j] = max(buy[j] + prices[i], sell[j]);
                    buy[j] = max((j == 0) ? -prices[i] : sell[j - 1] - prices[i], buy[j]);
                    if (i == prices.size() - 1 && maxSell < sell[j]) maxSell = sell[j];
                }
            }
            return maxSell;
        }
        return 0;
    }
};