class Solution {
public:
    bool iscorrect(char ch){
        return (ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
    }
    bool isvowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return false;
        int flag1=0,flag2=0;
        for(auto it:word){
            if(!iscorrect(it)) return false;
            if((it>='a' && it<='z') || (it>='A' && it<='Z')){
                if(isvowel(tolower(it))) flag1=1;
                else flag2=1;
            }
        }
        return flag1==1 && flag2==1;
    }
};