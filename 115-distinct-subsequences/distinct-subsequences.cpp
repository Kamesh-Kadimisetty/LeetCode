class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<double>curr(m+1,0);
        curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(i<j) continue;
                if(s[i-1]==t[j-1]){
                    curr[j]=curr[j-1]+curr[j];
                }
            }
        }
        return (int)curr[m];
    }
};