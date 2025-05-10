class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=accumulate(nums1.begin(),nums1.end(),0LL);
        long long sum2=accumulate(nums2.begin(),nums2.end(),0LL);
        int cnt1=0,cnt2=0;
        for(auto it:nums1){
            if(it==0) cnt1++;
        }
        for(auto it:nums2){
            if(it==0) cnt2++;
        }
        if(sum1==sum2){
            if((cnt1==0 && cnt2!=0) || (cnt2==0 && cnt1!=0)) return -1;
            return sum1+((cnt1<cnt2)?cnt2:cnt1);
        }
        if(sum1>sum2){
            if(cnt2==0 || (cnt1==0 && sum1-sum2<cnt2)) return -1;
        }
        else{
            if(cnt1==0 || (cnt2==0 && sum2-sum1<cnt1)) return -1;
        }
        return max(sum2+cnt2,sum1+cnt1);
    }
};