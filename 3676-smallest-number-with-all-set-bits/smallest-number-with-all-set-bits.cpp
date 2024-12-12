class Solution {
public:
    int smallestNumber(int n) {
        int i=0;
        while(1){
            int s=pow(2,i)-1;
            if(s>=n){
                return s;
            }
            i++;
        }
        return 0;
    }
};