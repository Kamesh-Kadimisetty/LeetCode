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
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insert(nums[i]);
        }
        int maxresult=0;
        for(int i=0;i<n;i++){
            maxresult=max(maxresult,trie.findmax(nums[i]));
        }
        return maxresult;
    }
};