#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> L[26];

bool OneColorability(){
    for(int i=0;i<26;++i) if(!L[i].empty()) return false;
    return true;
}

int color[26];

bool TwoColorability(){
    int S[26],sz,v;
    
    memset(color,-1,sizeof(color));
    
    for(int i=0;i<26;++i){
        if(color[i]!=-1) continue;
        
        S[0] = i; color[i] = 0; sz = 1;
        
        while(sz){
            v = S[--sz];
            
            for(int j=L[v].size()-1;j>=0;--j){
                if(color[L[v][j]]==color[v]) return false;
                if(color[L[v][j]]!=-1) continue;
                color[L[v][j]] = 1-color[v];
                S[sz] = L[v][j];
                ++sz;
            }
        }
    }
    
    return true;
}

#define MAX_SIZE 26

int parent[MAX_SIZE],rank[MAX_SIZE],num_comp;

void Make_Set(const int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(const int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;
    --num_comp;
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

bool done;
int curr_comp;
vector<int> component[26];

void search(int n){
    if(n==-1){
        done = true;
        return;
    }
    
    int v = component[curr_comp][n];
    bool valid;
    
    for(int i=0;i<3;++i){
        valid = true;
        
        for(int j=L[v].size()-1;j>=0;--j){
            if(color[L[v][j]]==i){
                valid = false;
                break;
            }
        }
        
        if(!valid) continue;
        color[v] = i;
        search(n-1);
        if(done) return;
    }
    
    color[v] = -1;
}

bool used[26];

bool ThreeColorability(){
    num_comp = 26;
    
    for(int i=0;i<26;++i) Make_Set(i);
    
    for(int i=0;i<26;++i)
        for(int j=L[i].size()-1;j>=0;--j)
            Union(i,L[i][j]);
    
    for(int i=0;i<26;++i) component[i].clear();
    
    memset(used,false,sizeof(used));
    
    for(int i=0,k=0;i<26;++i){
        if(used[i]) continue;
        
        for(int j=i;j<26;++j)
            if(Find(j)==Find(i)){
                component[k].push_back(j);
                used[j] = true;
            }
        
        ++k;
    }
    
    memset(color,-1,sizeof(color));
    
    for(int i=0;i<num_comp;++i){
        curr_comp = i; done = false;
        search(component[i].size()-1);
        if(!done) return false;
    }
    
    return true;
}

int main(){
    int N,l,u,v;
    char s[30];
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<26;++i) L[i].clear();
        
        for(int i=0;i<N;++i){
            scanf("%s",s);
            l = strlen(s);
            
            u = s[0]-'A';
            
            for(int j=2;j<l;++j){
                v = s[j]-'A';
                L[u].push_back(v);
            }
        }
        
        if(OneColorability()) printf("1 channel needed.\n");
        else if(TwoColorability()) printf("2 channels needed.\n");
        else if(ThreeColorability()) printf("3 channels needed.\n");
        else printf("4 channels needed.\n");
    }
    
    return 0;
}

