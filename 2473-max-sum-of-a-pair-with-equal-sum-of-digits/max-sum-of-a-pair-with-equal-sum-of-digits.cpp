class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int result=INT_MIN;
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=digitsum(nums[i]);
            if(mpp.find(sum)!=mpp.end()){
                result=max(result,mpp[sum]+nums[i]);
                mpp[sum]=max(mpp[sum],nums[i]);
            }
            else{
                mpp[sum]=nums[i];
            }
        }
        return result==INT_MIN?-1:result;
    }
};