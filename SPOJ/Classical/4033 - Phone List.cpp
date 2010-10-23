#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int ALPH_SIZE = 10;

struct Node{
    int words;              // numero de palabras que terminan en el nodo
    int prefixes;           // numero de palabras que tienen como prefijo el camino al nodo
    vector<Node*> links;    // enlaces a los nodos hijos
    
    Node(){
        words = prefixes = 0;
        links.resize(ALPH_SIZE,NULL);
    }
};

class Trie{
    public :
    
    Trie(){
        myRoot = new Node();
        myCount = 1;
    }
    int countPrefixes(const string& s) const;
    void insert(const string s);
    
    private :
    
    Node* myRoot;       // raiz del trie
    int myCount;        // # nodos del trie
};

int Trie::countPrefixes(const string& s) const{
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'0']==NULL) return 0;
        t = t->links[s[k]-'0'];
    }
    
    return t->prefixes;
}

void Trie::insert(const string s){
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
	    if(t->links[s[k]-'0']==NULL){
	        t->links[s[k]-'0'] = new Node();
	        ++myCount;
	    }
	    t = t->links[s[k]-'0'];
	    ++(t->prefixes);
    }
    
    ++(t->words);
}

int main(){
    int T,N;
    char aux[100001];
    string phone[100000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        Trie* myTrie;
        myTrie = new Trie();
        
        bool valid = true;
        
        for(int i = 0;i<N;++i){
            scanf("%s",aux);
            phone[i] = string(aux);
        }
        
        sort(phone,phone+N);
        
        for(int i=N-1;i>=0 && valid;--i){
            myTrie->insert(phone[i]);
            if(myTrie->countPrefixes(phone[i])>1) valid = false;
        }
        
        delete myTrie;
        
        printf("%s\n",valid? "YES" : "NO");
    }
        
    return 0;   
}
