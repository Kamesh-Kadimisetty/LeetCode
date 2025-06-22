class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size(),i=0;
        vector<string>result;
        for(int i=0;i<n;i+=k){
            string ans;
            for(int j=i;j<i+k;j++){
                if(j<n)ans+=s[j];
                else ans+=fill;
            }
            result.push_back(ans);
        }
        return result;
    }
};