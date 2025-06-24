class Node{
    public:
    Node* links[2];

    bool containskey(char ch){
        return links[ch-'0']!=NULL;
    }

    void put(char ch,Node* node){
        links[ch-'0']=node;
    }

    Node* get(char ch){
        return links[ch-'0'];
    }
};
class Trie {
public:
    Node* root;
    Trie() {
       root=new Node(); 
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containskey(word[i])){
                curr->put(word[i],new Node());
            }
            curr=curr->get(word[i]);
        }
    }

    int findmax(string binary){
        Node* curr=root;
        int ans=0;
        for(int i=0;i<binary.size();i++){
            int x=binary[i]=='1'?'0':'1';
            if(curr->containskey(x)){
                ans+=pow(2,31-i);
                curr=curr->get(x);
            }
            else{
                curr=curr->get(binary[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    string to_binary(int num){
        string ans;
        while(num>0){
            ans+=num%2==1?'1':'0';
            num/=2;
        }
        while(ans.size()<32) ans+='0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie trie;
        for(int i=0;i<n;i++){
            string binary=to_binary(nums[i]);
            trie.insert(binary);
        }
        int maxresult=0;
        for(int i=0;i<n;i++){
            string binary=to_binary(nums[i]);
            maxresult=max(maxresult,trie.findmax(binary));
        }
        return maxresult;
    }
};