class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>>pq;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                visited[-1*pq.top().second]=1;
                visited[i]=1;
                pq.pop();
            } 
            else pq.push({s[i],-i});
        }
        string result;
        for(int i=0;i<n;i++){
            if(visited[i]==0) result+=s[i];
        }
        return result;
    }
};