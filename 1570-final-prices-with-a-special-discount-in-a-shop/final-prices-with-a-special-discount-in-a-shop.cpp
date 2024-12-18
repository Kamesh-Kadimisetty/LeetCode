class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size(),j;
        vector<int>fprices;
        for(int i=0;i<n;i++){
            int ind=-1;
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    ind=j;
                    break;
                }
                else{
                    ind=-1;
                }
            }
            if(ind==-1){
                fprices.push_back(prices[i]);
            }
            else{
                fprices.push_back(prices[i]-prices[ind]);
            }
        }
        return fprices;
    }
};