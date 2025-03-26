class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int mintime=0,i=0,j=1;
        while(j<n){
            if(colors[i]==colors[j]){
                j++;
            }
            else{
                if(j-i>1){
                    int maxele=neededTime[i];
                    int sum=0;
                    for(int k=i;k<j;k++){
                        sum+=neededTime[k];
                        if(neededTime[k]>maxele){
                            maxele=neededTime[k];
                        }
                    }
                    mintime+=sum-maxele;
                }
                i=j;
                j++;
            }
        }
        if(j-i>1){
            int maxele=neededTime[i];
            int sum=0;
            for(int k=i;k<j;k++){
                sum+=neededTime[k];
                if(neededTime[k]>maxele){
                    maxele=neededTime[k];
                }
            }
            mintime+=sum-maxele;
        }
        return mintime;
    }
};