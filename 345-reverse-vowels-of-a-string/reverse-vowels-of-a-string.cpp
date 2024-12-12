class Solution {
public:
    bool isvowel(char ch) { 
        return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u') ||
        (ch == 'A') || (ch == 'E') ||(ch == 'I') ||(ch == 'O') ||(ch == 'U'); 
    } 
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(isvowel(s[i])&&isvowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            if(!isvowel(s[i])){
                i++;
            }
            if(!isvowel(s[j])){
                j--;
            }
        }
        return s;
    }
};