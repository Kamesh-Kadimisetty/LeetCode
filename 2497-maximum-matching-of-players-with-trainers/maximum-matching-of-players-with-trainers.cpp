class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int total=0,i=0,j=0;
        int n=players.size(),m=trainers.size();
        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                total++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return total;
    }
};