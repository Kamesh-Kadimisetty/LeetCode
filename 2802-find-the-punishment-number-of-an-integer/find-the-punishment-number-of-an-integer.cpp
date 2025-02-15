class Solution {
public:
    bool func(int num,int target){
        if(target<0 || num<target){
            return false;
        }
        if(num==target){
            return true;
        }
        return func(num/10,target-num%10)|| func(num/100,target-num%100) || func(num/1000,target-num%1000);
    }
    int punishmentNumber(int n) {
        int result=0;
        for(int i=1;i<=n;i++){
            if(func(i*i,i)){
                result+=(i*i);
            }
        }
        return result;
    }
};