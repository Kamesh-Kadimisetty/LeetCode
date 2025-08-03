class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int index=0,i=0;
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i>0) index=i;
        else return false;
        cout<<i<<endl;
        while(i<n-1 && nums[i]>nums[i+1]){
            i++;
        }
        if(i>index) index=i;
        else return false;
        cout<<i<<endl;
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i>index && i==n-1) index=i;
        else return false;
        cout<<i<<endl;
        return true;
    }
};