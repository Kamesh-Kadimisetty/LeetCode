class Solution {
public:
    int factorial(int n){
        if(n==0 || n==1){
            return 1;
        }
        return n*factorial(n-1);
    }
    void func(vector<int>&nums,int k,string& ans){
        int n=nums.size();
        if(n==0){
            return;
        }
        int total=factorial(n);
        int oneset=total/n;
        int index=k/oneset;
        int firstnum=nums[index];
        cout<<firstnum;
        ans+=to_string(firstnum);
        nums.erase(nums.begin()+index);
        k=(k==0?0:k%oneset);
        func(nums,k,ans);
    }
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        k--;
        string ans="";
        func(nums,k,ans);
        return ans;
    }
};