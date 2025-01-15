class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                cnt1++;
            }
            else if(moves[i]=='R'){
                cnt1--;
            }
            else if(moves[i]=='U'){
                cnt2++;
            }
            else if(moves[i]=='D'){
                cnt2--;
            }
        }
        return cnt1==0 && cnt2==0;
    }
};