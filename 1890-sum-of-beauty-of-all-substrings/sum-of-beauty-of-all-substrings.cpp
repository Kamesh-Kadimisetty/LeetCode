class Solution {
public:
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                int maxi=INT_MIN,mini=INT_MAX;
                for(auto it:mpp){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};