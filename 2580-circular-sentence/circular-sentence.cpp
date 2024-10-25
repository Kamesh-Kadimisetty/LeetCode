class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>res;
        int ind=0,count=0;
        sentence.append(" ");
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                res.push_back(sentence.substr(ind,count));
                ind=i+1;
                count=0;
            }
            else{
                count++;
            }
        }
        int n=res.size();
        if(n==1){
            if(res[0][0]!=res[0][res[0].size()-1]){
                return false;
            }
        }
        for(int i=0;i<n-1;i++){
            if(res[i][res[i].size()-1]!=res[i+1][0]){
                return false;
            }
        }
        if(res[0][0]!=res[n-1][res[n-1].size()-1]){
            return false;
        }
        return true;
    }
};