class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,int>mpp;
        int n=nums.size();
        int cnt=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            long long sum=nums[i]-stoi(s);
            cout<<sum<<endl;
            if(mpp.find(sum)!=mpp.end()){
                cnt=(cnt+mpp[sum])%mod;
            }
            mpp[sum]++;
        }
        return cnt;
    }
};