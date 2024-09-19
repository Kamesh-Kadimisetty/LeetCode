class Solution {
public:
    int perform(int x,int y,char op){
        if(op=='+') return x+y;
        if(op=='-') return x-y;
        if(op=='*') return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string exp) {
        vector<int> result;
        bool isnumber=1;
        for(int i=0;i<exp.length();i++){
            if(!isdigit(exp[i])){
                isnumber=0;
                vector<int> left=diffWaysToCompute(exp.substr(0,i));
                vector<int> right=diffWaysToCompute(exp.substr(i+1));
                for(int x:left){
                    for(int y:right){
                        int val=perform(x,y,exp[i]);
                        result.push_back(val);
                    }
                }
            }
        }
        if(isnumber==1) result.push_back(stoi(exp));
        return result;
    }
};