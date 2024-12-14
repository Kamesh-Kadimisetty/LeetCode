class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int>ocuurences;
        int cnt=1,start=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=start){
                ocuurences.push_back(cnt);
                cnt=1;
                start=arr[i];
            }
            else{
                cnt++;
            }
        }
        ocuurences.push_back(cnt);
        sort(ocuurences.begin(),ocuurences.end());
        for(int i=1;i<ocuurences.size();i++){
            if(ocuurences[i-1]==ocuurences[i]){
                return false;
            }
        }
        return true;
    }
};