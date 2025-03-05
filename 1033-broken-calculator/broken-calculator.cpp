class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue>target){
            return startValue-target;
        }
        long long cnt=0;
        while(target!=startValue){
            if(target<startValue){
                cnt+=(startValue-target);
                break;
            }
            else{
                cnt+=target%2==1?1:0;
                if(target%2==1){
                    target+=1;
                }
                target/=2;
                cnt++;
            }
        }
        return cnt;
    }
};