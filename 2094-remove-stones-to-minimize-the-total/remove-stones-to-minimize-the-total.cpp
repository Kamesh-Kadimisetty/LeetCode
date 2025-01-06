class Solution{
public:
    int minStoneSum(vector<int>& piles,int k){
        int n=piles.size();
        priority_queue<int>pq(piles.begin(),piles.end());
        while(k--){
            int val=pq.top();
            pq.pop();
            pq.push(val-floor(val/2));
        }
        int total=0;
        while(!pq.empty()){
            total+=pq.top();
            pq.pop();
        }
        return total;
    }
};