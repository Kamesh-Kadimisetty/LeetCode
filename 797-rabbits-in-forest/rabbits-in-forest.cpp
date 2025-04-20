class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size(),ans=0;
        unordered_map<int,int>mpp;
        for(auto it:answers){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.first==0){
                ans+=it.second;
            }
            else if(it.second>it.first+1){
                if((it.second%(it.first+1))==0) ans+=((it.second/(it.first+1)))*(it.first+1);
                else ans+=((it.second/(it.first+1))+1)*(it.first+1);
            }
            else{
                ans+=it.first+1;
            }
        }
        return ans;
    }
};