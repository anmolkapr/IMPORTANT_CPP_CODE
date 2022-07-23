#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* child[26];
    int count[26];
    TrieNode(int x){
        this->data = x;
        int i;
        for(i =0 ; i < 26;i++)child[i] = NULL;
        for(i= 0 ; i < 26;i++)count[i] =0 ;
    }
};

class Trie{
    public:
    
    TrieNode* root;
    
    Trie(){
       root = new TrieNode('0');
    }
    
    void insertwordh(TrieNode* node, string s){
        if(s.length() == 0)return ;
        
        int x = s[0] - 'a';
        TrieNode* t1 ;
        if(node->child[x] != NULL){
            t1 = node->child[x];
            node->count[x]++;
        }else{
            t1 = new TrieNode(s[0]);
            node->child[x] = t1;
            node->count[x]++;
        }
        insertwordh(t1,s.substr(1));
    }
    
    void insertword(string s){
        insertwordh(root,s);
    }
    
    string prefix(TrieNode* node, string s){
         if(s.length() == 0){
             string s1 = "";
             return s1;
         }
         
         int x = s[0] - 'a';
         string dum ;
         if(node->count[x] != 1){
             dum = prefix(node->child[x],s.substr(1));
         }else{
             dum.push_back(s[0]);
         }
         if(node->data != '0'){
             dum.push_back(node->data);
         }
         return dum;
    }
    
    string prefixh(string s){
        string d =  prefix(root,s);
        reverse(d.begin(),d.end());
        return d;
    }
    
};


vector<string> prefix(vector<string> &A) {
    int i;
    int n = A.size();
    Trie t;
    for(i =0 ;i < n;i++){
        t.insertword(A[i]);        
    }
    vector<string> c;
    
    for(i =0 ; i < n;i++){
        
        cout << t.prefixh(A[i]) << " ";
    }
    
    return c;
}


int main(){

}