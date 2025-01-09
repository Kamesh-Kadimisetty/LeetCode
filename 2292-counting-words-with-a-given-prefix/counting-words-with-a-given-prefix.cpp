class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        int n=pref.size();
        for(auto it:words){
            if(it.size()>=n){
                string s=it.substr(0,n);
                cnt+=(s==pref);
            }
        }
        return cnt;
    }
};