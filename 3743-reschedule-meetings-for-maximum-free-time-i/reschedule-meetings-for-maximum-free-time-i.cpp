class Solution {
public:
    int maxFreeTime(int eventime, int k, vector<int>& startime, vector<int>& endtime) {
        int n=startime.size();
        vector<int>freetimes;
        int time=0;
        for(int i=0;i<n;i++){
            if(startime[i]>time){
                freetimes.push_back(startime[i]-time);
            }
            else{
                freetimes.push_back(0);
            }
            time=endtime[i];
        }
        if(time<eventime) freetimes.push_back(eventime-time);
        for(auto it:freetimes) cout<<it<<" ";
        int result=0,sum=0;
        for(int i=0;i<freetimes.size();i++){
            sum+=freetimes[i];
            result=max(result,sum);
            if(i>=k) sum-=freetimes[i-k];
        }
        return result;
    }
};