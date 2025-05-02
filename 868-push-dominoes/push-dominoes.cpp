class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size(),cnt=0;
        vector<int>force(n,0);
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R') cnt=n;
            else if(dominoes[i]=='L') cnt=0;
            else cnt=max(cnt-1,0);
            force[i]+=cnt;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L') cnt=n;
            else if(dominoes[i]=='R') cnt=0;
            else cnt=max(cnt-1,0);
            force[i]-=cnt;
        }
        for(int i=0;i<n;i++){
            if(force[i]==0) dominoes[i]='.';
            else if(force[i]>0) dominoes[i]='R';
            else dominoes[i]='L';
        }
        return dominoes;
    }
};