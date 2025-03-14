class Solution {
public:
    bool ispossible(vector<int>& candies, long long k,long long mid){
        for(auto it:candies){
            if(it>=mid){
                k-=it/mid;
            }
        }
        return k<=0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long total=accumulate(candies.begin(),candies.end(),0LL);
        if(total<k)return 0;
        int low=1,high=*max_element(candies.begin(),candies.end());
        while(low<=high){
            cout<<low<<" "<<high<<endl;
            long long mid=(low+high)/2;
            if(ispossible(candies,k,mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};