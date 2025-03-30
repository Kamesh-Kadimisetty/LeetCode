class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]=i;
        }
        int i=0,maxindex=-1,x=0;
        vector<int>result;
        while(i<n){
            maxindex=max(maxindex,mpp[s[i]]);
            if(i==maxindex) {
                result.push_back(i-x+1);
                x=i+1;
            }
            i++;
        }
        return result;
    }
};