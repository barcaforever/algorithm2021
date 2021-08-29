// 122 买卖股票的最佳时机

// 贪心：股票价格只要后面的比前面的高，就看做利润，进行累加；

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};