class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        for(int i=0;i<=n-m;i++){
            int j=0;
            while(j<m){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                j++;
            }
            if(j==m){
                return i;
            }
        }
        return -1;
    }
};