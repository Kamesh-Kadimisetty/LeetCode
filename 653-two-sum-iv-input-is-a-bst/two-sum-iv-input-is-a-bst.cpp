class BSTIterator {
public:
    stack<TreeNode*>st;
    //reverse->true->before
    //reverse->false->next
    bool reverse=true;
    BSTIterator(TreeNode* root,bool isreverse) {
        reverse=isreverse;
        pushall(root);
    }
    
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        int ans=curr->val; //store ans
        if(!reverse) pushall(curr->right);
        else pushall(curr->left);
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushall(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(reverse)node=node->right;
            else node=node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next(); //before
        while(i<j){
            if(i+j==k) return true;
            if(i+j<k) i=l.next();
            else j=r.next();  //before
        }
        return false;
    }
};