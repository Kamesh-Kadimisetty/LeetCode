class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int>mpp;
        for(auto it:hand){
            mpp[it]++;
        }
        for(auto it:mpp){
            int key=it.first;
            int cnt=it.second;
            if(cnt>0){
                for(int i=0;i<groupSize;i++){
                    int val=key+i;
                    if(mpp[val]<cnt)return false;
                    mpp[val]-=cnt;
                }
            }
        }
        return true;
    }
};