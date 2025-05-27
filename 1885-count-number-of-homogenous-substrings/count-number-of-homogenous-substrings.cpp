class Solution {
public:
    int countHomogenous(string s) {
        long long n=s.size(),cnt=1,ans=0;
        int MOD=1e9+7;
        vector<long long>freq;
        char ch=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==ch){
                cnt++;
            }
            else{
                freq.push_back(cnt);
                ch=s[i];
                cnt=1;
            }
        }
        freq.push_back(cnt);
        for(auto it:freq){
            ans=ans+(((it)*(it+1))/2)%MOD;
        }
        return ans;
    }
};