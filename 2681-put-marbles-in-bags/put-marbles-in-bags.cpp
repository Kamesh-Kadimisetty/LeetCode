class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(n==k)return 0;
        vector<int>diff(n-1);
        for(int i=0;i<n-1;i++){
            diff[i]=weights[i]+weights[i+1];
        }
        priority_queue<int>maxheap(diff.begin(),diff.end());
        long long maxscore=weights[0]+weights[n-1],x=k;
        while(!maxheap.empty() && x>1){
            maxscore+=maxheap.top();
            maxheap.pop();
            x--;
        }
        priority_queue<int,vector<int>,greater<int>>minheap(diff.begin(),diff.end());
        long long minscore=weights[0]+weights[n-1];
        x=k;
        while(!minheap.empty() && x>1){
            minscore+=minheap.top();
            minheap.pop();
            x--;
        }
        return abs(maxscore-minscore);
    }
};