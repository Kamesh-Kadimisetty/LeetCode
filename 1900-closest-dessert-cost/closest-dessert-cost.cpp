class Solution {
public:
    int ans=INT_MAX;
    void func(int ind,int currcost,vector<int>& toppings,int target){
        if(abs(currcost-target)<abs(ans-target) || 
            (abs(currcost-target)==abs(ans-target) && currcost<ans)){
            ans=currcost;
        }
        if(ind==toppings.size() || currcost>target+abs(ans-target)) return;
        func(ind+1,currcost,toppings,target);
        func(ind+1,currcost+toppings[ind],toppings,target);
        func(ind+1,currcost+2*toppings[ind],toppings,target);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n=baseCosts.size(),m=toppingCosts.size();
        for(int i=0;i<n;i++){
            func(0,baseCosts[i],toppingCosts,target);
        }
        return ans;
    }
};