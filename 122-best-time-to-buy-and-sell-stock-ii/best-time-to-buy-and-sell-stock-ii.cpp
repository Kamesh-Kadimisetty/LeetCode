class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,mini=prices[0];
        for(int i=0;i<prices.size();i++){
            if(mini<prices[i]){
                profit+=prices[i]-mini;
            }
            mini=prices[i];
        }
        return profit;
    }
};