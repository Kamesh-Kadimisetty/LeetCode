class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        int i=0,j=0;
        while(i<n && j<m){
            int st1=(str1[i]-'a'+26+1)%26;
            int st2=(str2[j]-'a'+26)%26;
            if(str1[i]==str2[j]||st1==st2){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==m){
            return true;
        }
        return false;
    }
};