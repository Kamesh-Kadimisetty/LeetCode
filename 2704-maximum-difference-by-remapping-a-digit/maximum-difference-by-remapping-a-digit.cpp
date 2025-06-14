class Solution {
public:
    int minMaxDifference(int num) {
        string maxnum=to_string(num);
        char mapdig;
        for(int i=0;i<maxnum.size();i++){
            if(maxnum[i]!='9'){
                mapdig=maxnum[i];
                break;
            }
        }
        for(int i=0;i<maxnum.size();i++){
            if(maxnum[i]==mapdig) maxnum[i]='9';
        }
        string minnum=to_string(num);
        mapdig=minnum[0];
        for(int i=0;i<minnum.size();i++){
            if(minnum[i]==mapdig) minnum[i]='0';
        }
        return stoi(maxnum)-stoi(minnum);
    }
};