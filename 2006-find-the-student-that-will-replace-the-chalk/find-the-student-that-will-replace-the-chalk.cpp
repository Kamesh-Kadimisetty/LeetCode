class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size(),i,res=-1;
        long long chalksum=accumulate(chalk.begin(),chalk.end(),0LL);
        k=k%chalksum;
        for(int i=0;i<n;i++){
            if(chalk[i]>k){
                res=i;
                break;
            }
            else{
                k-=chalk[i];
            }
        }
        return res;
    }
};
