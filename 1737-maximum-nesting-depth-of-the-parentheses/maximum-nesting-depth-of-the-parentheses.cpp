class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,maxlen=0;
        for(auto ch:s){
            if(ch=='('){
                cnt++;
            }
            else if(ch==')'){
                cnt--;
            }
            maxlen=max(maxlen,cnt);
        }
        return maxlen;
    }
};