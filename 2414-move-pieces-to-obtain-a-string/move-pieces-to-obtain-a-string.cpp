class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int i=0,j=0;
        while(i<n || j<n){
            while(start[i]=='_' && i<n){
                i++;
            }
            while(target[j]=='_' && j<n){
                j++;
            }
            if(start[i]!=target[j] || (start[i]=='L' && i<j) || (start[i]=='R' && i>j)){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};