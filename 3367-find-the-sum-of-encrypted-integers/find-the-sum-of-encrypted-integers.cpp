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
        if(count==1)return maxdigit;
        string s="";
        while(count!=0){
            s.append(to_string(maxdigit));
            count--;
        }
        return stoi(s);
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=encrypt(nums[i]);
        }
        return sum;
    }
};