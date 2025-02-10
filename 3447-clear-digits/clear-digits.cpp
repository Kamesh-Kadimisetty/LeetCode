class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        string result;
        for(auto ch:s){
            if(!(ch>='0' && ch<='9')){
                result+=ch;
            }
            else{
                result.pop_back();
            }
        }
        return result;
    }
};