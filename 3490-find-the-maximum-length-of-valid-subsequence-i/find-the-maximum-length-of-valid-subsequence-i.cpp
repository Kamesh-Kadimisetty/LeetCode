class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0,evenodd=0,oddeven=0,flag1=0,flag2=0;
        for(auto it:nums){
            if(it%2==0){
                even++;
                if(flag1==0){
                    evenodd++;
                    flag1=1;
                }
                if(flag2==1){
                    oddeven++;
                    flag2=0;
                }
            }
            else{
                odd++;
                if(flag1==1){
                    evenodd++;
                    flag1=0;
                }
                if(flag2==0){
                    oddeven++;
                    flag2=1;
                }
            }
        }
        return max({odd,even,oddeven,evenodd});
    }
};