class Solution {
public:
    long long totalhrs(vector<int>& arr,int mid){
        int n=arr.size();
        long long  ans=0;
        for(int i=0;i<n;i++){
            ans+=ceil(double(arr[i])/double(mid));
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long tothrs=totalhrs(piles,mid);
            if(tothrs<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};