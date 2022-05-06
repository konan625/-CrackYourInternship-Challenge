//Type I: At most one transaction is allowed
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute
        int sum=0;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]>prices[i]){
                    sum=max(sum,prices[j]-prices[i]);
                }
            }
        }
        return sum;
        //Optimised
        int mini=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            profit=max(profit,prices[i]-mini);
        }
        return profit;
        //TC: O(N), SC: O(1)
        
    }
};

// Type II: Infinite transactions are allowed
//Explanation link - https://www.youtube.com/watch?v=HWJ9kIPpzXs
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int sell=prices[0];
        int profit=sell-buy;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>=sell){
                sell=prices[i];
            }else if(prices[i]<sell){
                profit+=(sell-buy);
                buy=sell=prices[i];
            }
        }
        profit+=(sell-buy);
        return profit;
        
    }
};

//Type III: At most two transactions are allowed
