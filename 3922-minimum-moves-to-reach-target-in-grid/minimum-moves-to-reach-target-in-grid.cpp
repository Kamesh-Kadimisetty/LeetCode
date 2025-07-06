class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        if(sx==tx && sy==ty) return 0;
        if(sx==0 && sy==0) return -1;
        int cnt=0;
        while(tx>sx || ty>sy){
            cnt++;
            if(ty>tx){
                swap(ty,tx);
                swap(sx,sy);
            }
            if(ty==tx){
                if(sx==0) tx=0;
                else ty=0;
            }
            else{
                if(tx<ty*2){
                    tx-=ty;
                }
                else{
                    if(tx%2) return -1;
                    tx/=2;
                }
            }
        }
        return tx<sx || ty<sy ?-1:cnt;
    }
};