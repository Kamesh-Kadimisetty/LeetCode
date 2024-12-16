class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((hours[j]+hours[i])%24==0 && i!=j){
                    cnt++;
                }
            }
        }
        return cnt/2;
    }
};