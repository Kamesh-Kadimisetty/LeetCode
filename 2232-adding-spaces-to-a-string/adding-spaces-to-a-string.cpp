class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.size(),m=spaces.size();
        string result;
        int j=0,k=0,i=0;
        for(int j=0;j<m+n;j++){
            if(i<m && j==spaces[i]+i){
                result+=' ';
                i++;
            }
            else{
                result+=s[k];
                k++;
            }
        }
        return result;
    }
};