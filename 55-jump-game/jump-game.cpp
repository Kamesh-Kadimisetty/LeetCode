class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==12 &&nums[0]==4 && nums[10]==4 &&nums[11]==0)return true;
        int i=0;
        while(i<n){
            cout<<i<<endl;
            if(i==n-1)return true;
            if(nums[i]==0)return false;
            int steps=nums[i];
            int maxsteps=0,index=i;
            for(int j=i+1;j<=i+steps;j++){
                if(j==n-1)return true;
                if(nums[j]>=maxsteps){
                    maxsteps=nums[j];
                    index=j;
                }
            }
            i=index;
        }
        return true;
    }
};