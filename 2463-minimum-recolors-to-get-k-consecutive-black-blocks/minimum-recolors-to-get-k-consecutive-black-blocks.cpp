class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int black=0,mincolor=INT_MAX;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B') black++;
        }
        mincolor=min(mincolor,k-black);
        for(int i=1;i<=n-k;i++){
            if(blocks[i+k-1]=='B') black++;
            if(blocks[i-1]=='B') black--;
            mincolor=min(mincolor,k-black);
        }
        return mincolor;
    }
};