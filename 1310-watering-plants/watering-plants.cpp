class Solution {
public:
    int wateringPlants(vector<int>& p, int capacity) {
        int ans=0,c=capacity;
        for(int i=0;i<p.size();i++){
            if(c>=p[i])
                ans++;
            else{
                ans+=i; 
                ans+=i+1;
                c=capacity;
            }
             c=c-p[i];
        }
        return ans;
    }
};