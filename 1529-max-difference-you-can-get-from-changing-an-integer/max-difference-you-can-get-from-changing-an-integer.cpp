class Solution {
public:
    int maxDiff(int num) {
        string maxnum=to_string(num),minnum=to_string(num);
        char mapchar,ch='x';
        int n=maxnum.size();
        for(int i=0;i<n;i++){
            if(maxnum[i]!='9'){
                mapchar=maxnum[i];
                break;
            } 
        }
        for(int i=0;i<n;i++){
            if(maxnum[i]==mapchar) maxnum[i]='9';
        }
        for(int i=0;i<n;i++){
            if(minnum[i]!='1' && minnum[i]!='0'){
                mapchar=minnum[i];
                ch=i==0?'1':'0';
                break;
            } 
        }
        if(ch!='x'){
            for(int i=0;i<n;i++){
                if(minnum[i]==mapchar) minnum[i]=ch;
            }
        }
        return stoi(maxnum)-stoi(minnum);
    }
};