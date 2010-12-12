#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int ALPH_SIZE = 26;

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
    }
    
    int countPrefixes(const string& s) const;
    void printAllWords(const Node* t, const string& s) const;
    
    void insert(const string s);
    
    Node* myRoot;       // raiz del trie
};

int Trie::countPrefixes(const string& s) const{
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'a']==NULL) return 0;
        t = t->links[s[k]-'a'];
    }
    
    return t->prefixes;
}

void Trie::insert(const string s){
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
	    if(t->links[s[k]-'a']==NULL) t->links[s[k]-'a'] = new Node();
	    t = t->links[s[k]-'a'];
	    ++(t->prefixes);
    }
    
    ++(t->words);
}

double code[8],tmp[8];

char getChar(){
    for(int i = 0;i<8;++i){
        cin>>code[i];
        tmp[i] = code[i];
    }
    
    sort(tmp,tmp+8);
    int end = 0;
    
    for(end = 0;end<7;++end){
        double minX = max(tmp[end]/1.05,tmp[7]/2.10);
        double maxX = min(tmp[0]/0.95,tmp[end+1]/1.9);
        if(minX<=maxX) break;
    }
    
    double max_val = tmp[end];
    
    int ret = 0;
    for(int i = 0;i<8;++i) ret = ret*2+(code[i]<=max_val? 0 : 1);
    
    return (char)ret;
}

int main(){
    ios::sync_with_stdio(false);
    
    int N,Q;
    string prod[10000];
    
    while(cin>>N>>Q){
        Trie* myTrie;
        myTrie = new Trie();
        
        for(int i = 0;i<N;++i){
            cin>>prod[i];
            if(prod[i].size()>30) prod[i] = prod[i].substr(0,30);
            myTrie->insert(prod[i]);
        }
        
        int ans = 0;
        
        for(int q = 0,K;q<Q;++q){
            cin>>K;
            string query;
            
            for(int k = 0;k<K;++k)
                query += getChar();
            
            ans += myTrie->countPrefixes(query);
        }
        
        cout<<ans<<'\n';
        delete myTrie;
    }    
    
    return 0;
}
