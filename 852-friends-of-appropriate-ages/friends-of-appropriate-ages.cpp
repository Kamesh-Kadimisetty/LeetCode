class Solution {
public:
    bool request(int a,int b){
        return !(b>a || b<=0.5*a+7);
    }
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size();
        int requests=0;
        unordered_map<int,int>mpp;
        for(auto it:ages){
            mpp[it]++;
        }
        for(auto a:mpp){
            for(auto b:mpp){
                if(request(a.first,b.first)){
                    requests+=(a.second*(b.second-(a.first==b.first?1:0)));
                }
            }
        }
        return requests;
    }
};