class Solution {
public:
    int encrypt(int n){
        int maxdigit=0;
        int count=0,ans=0;
        while(n>0){
            maxdigit=max(maxdigit,n%10);
            n/=10;
            count++;
        }
        while(count>0){
            ans=ans*10+maxdigit;
            count--;
        }
        return ans;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=encrypt(nums[i]);
        }
        return sum;
    }
};