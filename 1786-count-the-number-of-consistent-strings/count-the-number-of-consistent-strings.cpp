class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        int arr[26]={0};
        for(auto c: allowed){
            arr[c-'a']=1;
        }
        for(auto word:words){
            int flag=1;
            for(auto c:word){
                if(arr[c-'a']==0){
                    flag=0;
                    break;
                }
            }
            count+=flag;
        }
        return count;
    }
};