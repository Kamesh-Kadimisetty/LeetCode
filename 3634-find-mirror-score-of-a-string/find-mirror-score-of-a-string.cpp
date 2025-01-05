class Solution {
public:
    long long calculateScore(string s) {
        int n=s.size();
        long long score=0;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            int curr=s[i]-'a';
            int mirror=25-curr;
            if(mpp.find(mirror)!=mpp.end() && mpp[mirror].size()>0){
                score+=(i-mpp[mirror].back());
                mpp[mirror].pop_back();
            }
            else{
                mpp[curr].push_back(i);
            }
        }   
        return score;
    }
};