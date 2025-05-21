class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro=INT_MIN,n=nums.size(),suff=1,pref=1;
        for(int i=0;i<n;i++){
            if(suff==0) suff=1;
            if(pref==0) pref=1;
            suff*=nums[i];
            pref*=nums[n-i-1];
            maxpro=max(maxpro,max(suff,pref));
        }   
        return maxpro;
    }
};