class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(),cnt=0;
        char ch1='.',ch2='.';
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i] && cnt==0){
                cnt++;
                ch1=s1[i];
                ch2=s2[i];
            }
            else if(s1[i]!=s2[i] && cnt==1){
                if(s1[i]!=ch2 || s2[i]!=ch1){
                    return false;
                }
                cnt++;
            }
            else if(s1[i]!=s2[i]) return false;
        }
        cout<<cnt;
        return (ch1=='.')|| (cnt==2);
    }
};