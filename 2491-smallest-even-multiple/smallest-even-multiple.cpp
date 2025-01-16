class Solution {
public:
    int smallestEvenMultiple(int n) {
        int m=n;
        while(1){
            if(m%2==0){
                return m;
            }
            m+=m;
        }
        return 0;
    }
};