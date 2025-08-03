class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size(),maxi=weight[0],result=0;
        for(int i=1;i<n;i++){
            if(weight[i]<maxi){
                result++;
                if(i!=n-1) maxi=weight[i+1];
            }
            else{
                maxi=max(maxi,weight[i]);
            }
        }
        return result;
    }
};