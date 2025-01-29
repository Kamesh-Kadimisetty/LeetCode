class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        int len=1,k=0;
        sort(strs.begin(),strs.end());
        if(strs[0].size()==0) return result;
        while(1){
            char ch=strs[0][k];
            int flag=0;
            for(int i=0;i<strs.size();i++){
                if(ch!=strs[i][k]){
                    flag=1;
                }
            }
            if(flag==0) result+=ch;
            if(flag==1) return result;
            k++;
            if(k>=strs[0].size()){
                return result;
            }
        }
        return result;
    }
};