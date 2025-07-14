class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string result;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr=qu.front();
            qu.pop();
            if(curr==NULL) result+="#,";
            else result+=to_string(curr->val)+',';
            if(curr!=NULL){
                qu.push(curr->left);
                qu.push(curr->right);
            }
        }
        cout<<result<<endl;
        return result;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr=qu.front();
            qu.pop();
            getline(s,str,',');
            if(str=="#"){
                curr->left=NULL;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                curr->left=leftnode;
                qu.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#"){
                curr->right=NULL;
            }
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                curr->right=rightnode;
                qu.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));