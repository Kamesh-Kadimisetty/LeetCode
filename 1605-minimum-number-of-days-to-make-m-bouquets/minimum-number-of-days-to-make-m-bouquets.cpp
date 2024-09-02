class Solution {
public:
    int possible(vector<int>&bloom,int m,int k,int mid){
        int noofboq=0,count=0;
        for(int i=0;i<bloom.size();i++){
            if(bloom[i]<=mid){
                count++;
            }
            else{
                noofboq+=(count/k);
                count=0;
            }
        }
        noofboq+=(count/k);
        return noofboq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(m*1LL)*(k*1LL)) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            int poss=possible(bloomDay,m,k,mid);
            if(poss>=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};