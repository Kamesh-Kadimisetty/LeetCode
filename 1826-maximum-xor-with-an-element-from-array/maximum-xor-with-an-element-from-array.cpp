class Node{
    public:
    Node* links[2];

    bool containskey(int ch){
        return links[ch]!=NULL;
    }

    void put(int ch,Node* node){
        links[ch]=node;
    }

    Node* get(int ch){
        return links[ch];
    }
};
class Trie {
public:
    Node* root;
    Trie() {
       root=new Node(); 
    }
    
    void insert(int num) {
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!curr->containskey(bit)){
                curr->put(bit,new Node());
            }
            curr=curr->get(bit);
        }
    }

    int findmax(int num){
        Node* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->containskey(1-bit)){
                ans=ans | (1<<i);
                curr=curr->get(1-bit);
            }         
            else{
                curr=curr->get(bit);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>qrs; /// {val,{num,index}}
        for(int i=0;i<queries.size();i++){
            qrs.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(qrs.begin(),qrs.end());
        int n=nums.size(),j=0;
        vector<int>result(qrs.size(),-1);
        for(auto it:qrs){
            int val=it.first;
            int num=it.second.first;
            int index=it.second.second;
            while(j<n && nums[j]<=val){
                trie.insert(nums[j]);
                j++;
            }
            if(j>0) result[index]=trie.findmax(num);
        }
        return result;
    }
};