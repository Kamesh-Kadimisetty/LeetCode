class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count=0;
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                count=0;
            }
            if(count<2){
                ans+=s[i];
            }
        }
        return ans;
    }
};