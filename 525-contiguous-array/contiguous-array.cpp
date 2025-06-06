class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=nums[0]==0?-1:1;
        for(int i=1;i<n;i++){
            if(nums[i]==0) nums[i]=-1;
            prefix[i]=prefix[i-1]+nums[i];
        }
        unordered_map<int,int>mpp;
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(prefix[i]==0){
                maxlen=max(maxlen,i+1);
            }
            else if(mpp.find(prefix[i])!=mpp.end()){
                maxlen=max(maxlen,i-mpp[prefix[i]]);
            }
            else{
                mpp[prefix[i]]=i;
            }
        }
        return maxlen;
    }
};