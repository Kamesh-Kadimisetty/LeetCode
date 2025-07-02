class Solution {
public:
    int possibleStringCount(string word, int k) {
        int MOD=1e9+7;
        int n=word.size(),cnt=1;
        vector<int>temp;
        for(int i=1;i<n;i++){
            if(word[i]!=word[i-1]){
                temp.push_back(cnt);
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        temp.push_back(cnt);
        int m=temp.size();
        long long prod=1;
        for(int i=0;i<m;i++) prod=(prod*temp[i])%MOD;
        if(m>=k) return prod;
        vector<int> dp(k, 0);
        dp[0]=1;
        for (auto num:temp) {
            vector<int> curr(k,0);
            long long sum=0;
            for (int s=0;s<k;s++) {
                if (s>0) sum=(sum+dp[s-1])%MOD;
                if (s>num) sum=(sum-dp[s-num-1]+MOD)%MOD;
                curr[s]=sum;
            }
            dp=curr;
        }
        long long invalid=0;
        for (int s=temp.size();s<k;s++)
            invalid=(invalid+dp[s])%MOD;

        return (prod-invalid+MOD)%MOD;
    }
};