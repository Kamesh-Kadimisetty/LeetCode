class Solution {
public:
    Node* dfs(Node* curr,unordered_map<Node*,Node*>& mpp){
        vector<Node*>neighbour;
        Node* clone=new Node(curr->val);
        mpp[curr]=clone;
        for(auto it:curr->neighbors){
            if(mpp.find(it)!=mpp.end()) neighbour.push_back(mpp[it]);
            else neighbour.push_back(dfs(it,mpp));
        }
        clone->neighbors=neighbour;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mpp;
        if(node==NULL) return NULL;
        return dfs(node,mpp);
    }
};