class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long result=0;
        long long n=nums.size(),i=0,j=0,sum=0;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[nums[j]]++;
            sum+=nums[j];
            while(j-i+1>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k && mpp.size()>=m){
                cout<<i<<" "<<j<<" "<<sum<<endl;
                result=max(result,sum);
            }
            j++;
        }
        return result;
    }
};