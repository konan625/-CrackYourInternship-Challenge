You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Approach -1 Peak Valley
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        int profit=0;
        for(int i=0;i<n-1;i++){
            if(prices[i]<prices[i+1]) profit+=(prices[i+1]-prices[i]);
        }
        return profit;
    }
};
The general idea is to buy stock at valleys (lowest price) and then sell stock at its next peak (highest price). In the below graph, there are two valleys and two peaks. Since (1) we have to buy stock before selling it and (2) we can not have back-to-back buy or sell trades, thus there are two options of trading stocks.

Option 1: Buy stock at valley[i] then sell at peak[i] makes profit A (peak[i] - valley[i]). Then buy stock at valley [j] and sell at peak[j] makes proft B (peak[j] - valley[j]). So the total profit of this trade option is A + B.

Option 2: Skip the intermediate trades, i.e,, we buy stock at valley[i] then sell at peak[j]. In this case, the total profit will be C (peak[j]-valley[i]).

Based on the graph shown below, A + B > C (if not, peak[i] and valley[j] won't exist). So in order to maximize the profit, we can buy stock at valleys and then sell stock at peaks.
image'
https://assets.leetcode.com/users/danhuang/image_1584664753.png

Approach -2 Selling Price and Cost Price
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int sell=prices[0];
        int profit=sell-buy;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>=sell){
                sell=prices[i];
            }else{
                profit+=(sell-buy);
                buy=sell=prices[i];
            }
        }
        profit+=(sell-buy);
        return profit;
        
    }
};