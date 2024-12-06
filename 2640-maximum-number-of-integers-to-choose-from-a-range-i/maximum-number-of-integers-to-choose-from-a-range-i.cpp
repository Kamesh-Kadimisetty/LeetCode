class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count=0,sum=0;
        set<int>stt;
        for(int i=0;i<banned.size();i++){
            if(banned[i]<=n){
                stt.insert(banned[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(stt.find(i)==stt.end()){
                if(sum+i<=maxSum){
                    sum+=i;
                    count++;
                }
            }
        }
        return count;
    }
};