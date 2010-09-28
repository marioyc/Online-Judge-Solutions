#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

const int ALPH_SIZE = 26;  // tamaño del alfabeto

struct Node{
    vector<Node*> links;    // enlaces a los nodos hijos
    int val;
    
    Node();
};

Node::Node(){
    val = 0;
    links.resize(ALPH_SIZE,NULL);
}

class Trie{
    public :
    
    Trie();
    
    int getValue(const string& s) const;
    void insert(const string s, const int val);
    
    private :
    
    Node* myRoot;       // raíz del trie
};

Trie::Trie(){
    myRoot = new Node();
}

int Trie::getValue(const string& s) const{
    Node* t = myRoot;
    int len = s.size();
    
    for(int k=0;k<len;++k){
	    if(t==NULL || s[k]<'a' || s[k]>'z') return 0;
	    t = t->links[s[k]-'a'];
    }
    
    if(t==NULL) return 0;
    return t->val;
}

void Trie::insert(const string s, const int val){
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
	    if(t->links[s[k]-'a']==NULL){
	        t->links[s[k]-'a'] = new Node();
	    }
	    t = t->links[s[k]-'a'];
    }
    
    t->val += val;
}

int main(){
    int m,n,val,ans;
    string s,line;
    
    while(cin>>m>>n){
        Trie *myTrie;
        myTrie = new Trie();
        
        for(int i=0;i<m;++i){
            cin>>s>>val;
            myTrie->insert(s,val);
        }
        
        for(int i=0;i<n;++i){
            ans = 0;
            
            while(true){
                getline(cin,line);
                if(line==".") break;
                
                istringstream is(line);
                
                while(is>>s) ans += myTrie->getValue(s);
            }
            
            cout<<ans<<endl;
        }
        
        delete myTrie;
    }
    
    return 0;
}
