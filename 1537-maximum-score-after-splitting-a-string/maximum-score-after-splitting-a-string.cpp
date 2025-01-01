class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int>ones(n);
        ones[0]=s[0]=='0'?0:1;
        for(int i=1;i<n;i++){
            ones[i]=ones[i-1]+(s[i]=='0'?0:1);
        }
        int zeros=0,ans=0;
        for(int i=0;i<n-1;i++){
            zeros+=(s[i]=='0'?1:0);
            ans=max(ans,zeros+ones[n-1]-ones[i]);
        }
        return ans;
    }
};