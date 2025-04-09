class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0,n=nums.size(),i;
        sort(nums.begin(),nums.end());
        if(n==1){
            if(nums[0]==k){
                return 0;
            }
            else if(nums[0]<k){
                return -1;
            }
            else{
                return 1;
            }
        }
        while(true){
            int maxval=nums[n-1];
            int secondmax=-1;
            for(i=n-2;i>=0;i--){
                if(nums[i]!=maxval){
                    secondmax=nums[i];
                    break;
                }
            }
            // cout<<secondmax;
            if(secondmax==-1){
                if(nums[0]==k){
                    return count;
                }
                if(nums[0]==nums[1]) {
                    return count+1;
                }
            }
            if(secondmax<k){
                return -1;
            }
            for(int i=0;i<n;i++){
                if(nums[i]>secondmax){
                    nums[i]=secondmax;
                }
            }
            count++;
            bool allequal=true;
            for(int i=0;i<n;i++){
                if(nums[i]!=k){
                    allequal=false;
                }
            }
            if(allequal){
                return count;
            }
        }
        return -1;
    }
};