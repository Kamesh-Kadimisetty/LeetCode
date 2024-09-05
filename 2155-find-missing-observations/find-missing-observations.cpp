class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int meansum=mean*(m+n);
        int sum=accumulate(rolls.begin(),rolls.end(),0);
        int diff=meansum-sum;
        if(diff>6*n || diff<n){
            return {};
        }
        int x=diff/n;
        int rem=diff%n;
        vector<int> res(n,x);
        for(int i=0;i<rem;i++){
            res[i]++;
        }
        return res;
    }
};