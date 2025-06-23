class Node{
    public:
    Node* links[26];
    bool flag=false;

    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setend(){
        flag=true;
    }

    bool isend(){
        return flag;
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
        curr->setend();
    }
    
    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containskey(word[i])){
                return false;
            }
            curr=curr->get(word[i]);
        }
        return curr->isend();
    }
    
    bool startsWith(string prefix) {
                Node* curr=root;
        for(int i=0;i<prefix.size();i++){
            if(!curr->containskey(prefix[i])){
                return false;
            }
            curr=curr->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */