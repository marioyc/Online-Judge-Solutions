#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct nodo{
    int num;
    vector<nodo> v;
    
    nodo(int _num){
        num=_num;
    }
};

char c1,c2;

int f(char s[4]){
    int a,b;
    
    if(strlen(s)==3){
        a=10;
        c2=s[2];
    }else{
        c1=s[0]; c2=s[1];
        if(c1=='A') a=1;
        else if(c1=='J') a=11;
        else if(c1=='Q') a=12;
        else if(c1=='K') a=13; 
        else a=c1-'0';
    }
    
    if(c2=='C') b=0;
    else if(c2=='D') b=1;
    else if(c2=='H') b=2;
    else b=3;
    
    return 13*b+a;
}

int cont;

int find(int &X, vector<nodo> &v){
    for(int i=v.size()-1;i>=0;i--)
        if(X==v[i].num) return i;
    
    cont++;
    
    v.push_back(nodo(X));
    return v.size()-1;
}

void insert(vector<int> &a, vector<nodo> &b){
    vector<nodo> *p;
    p=&b;
    
    for(int i=0;i<a.size();i++) p=&((*p)[find(a[i],*p)].v);
}

int main(){    
    int N,M;
    vector<nodo> trie;
    vector<int> v;
    char s[4];
    
    while(1){
        scanf("%d\n",&N);
        if(N==0) break;
        
        trie.clear();
        cont=0;
        
        for(int i=0;i<N;i++){
            scanf("%d",&M);
            
            v.clear();
            
            for(int j=0;j<M;j++){
                scanf(" %s",s);
                v.push_back(f(s));
            }
            
            sort(v.rbegin(),v.rend());
            
            insert(v,trie);
        }
        
        printf("%d\n",cont);
    }
    
    return 0;
}
