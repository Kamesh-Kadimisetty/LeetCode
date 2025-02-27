class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children)return -1;
        int money1=money;
        money-=children;
        int ans=min(children,money/7);
        cout<<ans;
        if((ans==children && money%7!=0) || (ans==children && ans*8!=money1)){
            if(ans>0)ans--;
        }
        else if(money%7==3 && children-ans==1){
            if(ans>0)ans--;
        }
        return ans;
    }
};