/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void transversepostorder(Node* currentnode,vector<int>&result){
        if(!currentnode){
            return;
        }
        for(auto childnode:currentnode->children){
            transversepostorder(childnode,result);
        }
        result.push_back(currentnode->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> result;
        if(root==nullptr) return result;
        transversepostorder(root,result);
        return result;
    }
};