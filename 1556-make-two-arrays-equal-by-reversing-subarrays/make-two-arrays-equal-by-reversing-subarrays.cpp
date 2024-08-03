class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        bool answer=1;
        for(int i=0;i<arr.size();i++){
            if(target[i]!=arr[i]){
                answer=0;
                break;
            }
        }
        return answer;
    }
};