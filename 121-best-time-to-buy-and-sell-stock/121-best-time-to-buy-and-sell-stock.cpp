class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitCount=0;
        int currentMax = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            currentMax = min(currentMax,prices[i]);
            maxProfitCount = max(maxProfitCount,prices[i]-currentMax);
            
        }
        return maxProfitCount;
    }
};