#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int ALPH_SIZE = 26;

struct Node{
    vector<Node*> links;
    bool used;
    string val;
    Node();
};

Node::Node(){
    links.resize(ALPH_SIZE,NULL);
    used = false;
};

class Trie{
    public :
    
    Trie();
    
    void printValue(const string &s) const;
    void insert(const string &s, const string &val);
    
    private :
    
    Node* myRoot;
};

Trie::Trie(){
    myRoot = new Node();
}

void Trie::printValue(const string &s) const{
    Node *t = myRoot;
    int len = s.size();
    
    for(int i=0;i<len;++i){
        if(t->links[s[i]-'a']==NULL){
            t = NULL;
            break;
        }
        t = t->links[s[i]-'a'];
    }
    
    if(t==NULL || (t->used)==false) fputs("eh\n",stdout);
    else{
        fputs((t->val).c_str(),stdout);
        putc('\n',stdout);
    }
}

void Trie::insert(const string &s, const string &val){
    Node *t = myRoot;
    int len = s.size();
    
    for(int i=0;i<len;++i){
        if(t->links[s[i]-'a']==NULL) t->links[s[i]-'a'] = new Node();
        t = t->links[s[i]-'a'];
    }
    
    t->val = val;
    t->used = true;
}

int main(){
    char line[22],s1[11],s2[11];
    string key,val;
    
    Trie *myTrie;
    myTrie = new Trie();
    
    while(true){
        fgets(line,3300001,stdin);
        if(strlen(line)==1) break;
        
        sscanf(line,"%s%s",s1,s2);
        key = string(s2);
        val = string(s1);
        myTrie->insert(key,val);
        
    }
    
    while(scanf("%s",s1)==1){
        key = string(s1);
        myTrie->printValue(key);
    }
    
    delete myTrie;
    
    return 0;
}
