class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt=0,sum=0,len=0;
        int i=0,j=0,n=nums.size();
        while(j<n){
            len++;
            sum+=nums[j];
            while(len*sum>=k){
                cnt+=n-j;
                len--;
                sum-=nums[i];
                i++;
            }
            j++;
        }
        long long s=n;
        long long total=(s*(s+1))/2;
        return total-cnt;
    }
};