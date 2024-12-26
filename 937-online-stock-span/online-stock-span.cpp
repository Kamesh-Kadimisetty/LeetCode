class StockSpanner {
public:
    vector<int>stocks;
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt=1;
        stocks.push_back(price);
        for(int i=stocks.size()-2;i>=0;i--){
            if(stocks[i]<=price){
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};