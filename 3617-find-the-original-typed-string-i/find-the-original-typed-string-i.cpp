class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size(),result=1,cnt=1;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                cnt++;
            }
            else{
                result+=(cnt-1);
                cnt=1;
            }
            if(i==n-1) result+=(cnt-1);
        }
        return result;
    }
};