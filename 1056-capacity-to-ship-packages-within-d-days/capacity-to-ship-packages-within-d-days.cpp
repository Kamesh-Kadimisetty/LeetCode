class Solution {
public:
    int capacity(vector<int> & weights,int mid){
        int days=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long low=*max_element(weights.begin(),weights.end());
        long long high=accumulate(weights.begin(),weights.end(),0LL);
        while(low<=high){
            long long mid=(low+high)/2;
            long long noofdays=capacity(weights,mid);
            if(noofdays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};