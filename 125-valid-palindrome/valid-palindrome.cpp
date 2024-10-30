class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int i=s.size()-1;i>=0;i--){
            if(!((s[i]>='a'&& s[i]<='z')||(s[i]>='0'&& s[i]<='9'))){
                s.erase(s.begin()+i);
            }
        }
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
};