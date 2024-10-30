class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int i=s.size()-1;i>=0;i--){
            if(!((s[i]>='a'&& s[i]<='z')||(s[i]>='0'&& s[i]<='9'))){
                s.erase(s.begin()+i);
            }
        }
        string rev=s;
        reverse(rev.begin(),rev.end());
        return rev==s;
    }
};