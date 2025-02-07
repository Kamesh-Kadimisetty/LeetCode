class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>result;
        int n=queries.size();
        unordered_map<int,int>mpp;
        unordered_map<int,int>colorcnt;
        set<int>st;
        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            if(mpp.find(ball)!=mpp.end()){
                int oldcolor=mpp[ball];
                if(colorcnt[oldcolor]==1){;
                    st.erase(oldcolor);
                }
                colorcnt[oldcolor]--;
            }
            mpp[ball]=color;
            st.insert(color);
            colorcnt[color]++;
            result.push_back(st.size());
        }
        return result;
    }
};