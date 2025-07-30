class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool>prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int p=2;p*p<=n;p++) {
            if(prime[p]==true) {
                for(int i=p*p;i<=n;i+=p){
                    prime[i]=false;
                }
            }
        }
        return prime;
    }

    int minJumps(vector<int>& nums) {
        int n=nums.size(),maxi=*max_element(nums.begin(),nums.end());
        vector<bool>primes=sieve(maxi);
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++) mpp[nums[i]].push_back(i);
        queue<int>qu;
        qu.push(0);
        vector<int>distance(n,-1);
        distance[0]=0;
        unordered_set<int>st;
        while(!qu.empty()){
            int ind=qu.front();
            qu.pop();
            if(ind+1<n && distance[ind+1]==-1){
                qu.push(ind+1);
                distance[ind+1]=distance[ind]+1;
            }
            if(ind-1>=0 && distance[ind-1]==-1){
                qu.push(ind-1);
                distance[ind-1]=distance[ind]+1;
            }
            if(primes[nums[ind]]==false || st.find(nums[ind])!=st.end()) continue;
            for(int x=nums[ind];x<=maxi;x+=nums[ind]){
                if(mpp.find(x)==mpp.end()) continue;
                for(auto it:mpp[x]){
                    if(distance[it]!=-1) continue;
                    qu.push(it);
                    distance[it]=distance[ind]+1;
                    if(it==n-1) return distance[it];
                }
            }
            st.insert(nums[ind]);
        }
        return distance[n-1];
    }
};