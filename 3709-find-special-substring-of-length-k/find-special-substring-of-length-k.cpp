class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.size();
        if(k==1 && n==1)return true;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                if(cnt==k){
                    return true;
                }
                cnt=1;
            }
            cout<<cnt<<endl;
        }
        if(cnt==k)return true;
        return false;
    }
};