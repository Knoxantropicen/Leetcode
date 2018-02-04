// Time: O(n), Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int toBuy = 0, toSell = -prices[0];    // have 0, have 1
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            int temp = toSell;
            toSell = max(toBuy - prices[i], toSell);
            toBuy = max(temp + prices[i], toBuy);
        }
        return toBuy;
    }
};

// Time: O(n), Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        int buyTime = 0, maxPro = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] < prices[i - 1]) {
                maxPro += prices[i - 1] - prices[buyTime];
                buyTime = i;
            }
        }
        return maxPro + max(prices[n - 1] - prices[buyTime], 0);
    }
};