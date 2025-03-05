class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue>target){
            return startValue-target;
        }
        // if(startValue>target/2){
        //     return startValue*2-target+1;
        // }
        long long cnt=0;
        while(target!=startValue){
            if(target<startValue){
                cnt+=(startValue-target);
                target+=(startValue-target);
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
            cout<<target<<" "<<cnt<<endl;
        }
        return cnt;
    }
};