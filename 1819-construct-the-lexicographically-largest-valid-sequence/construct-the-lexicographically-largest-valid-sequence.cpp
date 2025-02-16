class Solution {
public:
    bool func(int ind,vector<int>&result,vector<int>&visited,int n){
        if(ind==result.size()){
            return true;
        }
        if(result[ind]!=0){
            return func(ind+1,result,visited,n);
        }
        else{
            for(int i=n;i>=1;i--){
                if(visited[i])continue;
                visited[i]=1;
                result[ind]=i;
                if(i==1){
                    if(func(ind+1,result,visited,n)==true){
                        return true;
                    }
                }
                else if(ind+i<result.size() && result[ind+i]==0){
                    result[i+ind]=i;
                    if(func(ind+1,result,visited,n)==true){
                        return true;
                    }
                    result[i+ind]=0;
                }
                result[ind]=0;
                visited[i]=0;
            }
        }
        return false;
    } 
    vector<int>constructDistancedSequence(int n) {
        vector<int>result((2*n)-1,0);
        vector<int>visited(n+1,0);
        func(0,result,visited,n);
        return result;
    }
};