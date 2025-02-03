class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>chocolates(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                chocolates[i]=chocolates[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                chocolates[i]=max(chocolates[i],chocolates[i+1]+1);
            }
        }
        for(int i=0;i<n;i++){
            cout<<chocolates[i]<<" ";
        }
        int total=accumulate(chocolates.begin(),chocolates.end(),0);
        return total;
    }
};