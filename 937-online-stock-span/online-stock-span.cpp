class StockSpanner {
public:
    stack<pair<int,int>>st;
    int ind=-1;
    StockSpanner() {
        // ind=-1;
    }
    
    int next(int price) {
        ind=ind+1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans=ind-(st.empty()?-1:st.top().second);
        st.push({price,ind});
        return ans;
    }
};