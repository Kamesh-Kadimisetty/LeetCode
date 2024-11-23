class Solution {
public:
    int fillCups(vector<int>& amount) {
        int time=0;
        sort(amount.begin(),amount.end());
        while(amount[2]!=0){
            time++;
            amount[2]--;
            if(amount[1]>0){
                amount[1]--;
            }
            sort(amount.begin(),amount.end());
        }
        return time;
    }
};