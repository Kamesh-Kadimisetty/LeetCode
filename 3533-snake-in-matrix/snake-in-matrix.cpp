class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int c=0;
        for(auto it :commands){
            if(it=="DOWN") c+=n;
            else if(it=="UP") c-=n;
            else if(it=="LEFT") c-=1;
            else if(it=="RIGHT") c+=1; 
        }
        return c;
    }
};