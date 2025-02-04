class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int min=0,max=0;
        for(auto ch:s){
            if(ch=='('){
                min++;
                max++;
            }
            else if(ch==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min<0)min=0;
            if(max<0)return false;
        }
        return min==0;
    }
};