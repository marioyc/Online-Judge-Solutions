#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_N 50000

vector<int> L[MAX_N];
set<int> S[MAX_N];
bool solved[MAX_N],repeated[MAX_N];
int ind[MAX_N],ans[MAX_N];

void solve(int n){
    int son,aux,sz = -1,sz2,I;
    
    for(int i=L[n].size()-1;i>=0;--i){
        son = L[n][i];
        if(!solved[son]) solve(son);
        sz2 = S[ind[son]].size();
        
        if(sz2>sz){
            sz = sz2;
            I = ind[son];
        }
    }
    
    ind[n] = I;
    
    for(int i=L[n].size()-1;i>=0;--i){
        son = L[n][i];
        if(repeated[son]) repeated[n] = true;
        if(ind[son]==I) continue;
        if(repeated[n]) break;
        
        for(set<int>::iterator it=S[ind[son]].begin();it!=S[ind[son]].end();++it){
            aux = (*it);
            
            if(S[I].find(aux)!=S[I].end()){
                repeated[n] = true;
                break;
            }
            
            S[I].insert(aux);
        }
    }
    
    if(repeated[n]) ans[n] = 0;
    else{
        ans[n] = 2147483647;
        int prev;
        bool first = true;
        
        for(set<int>::iterator it=S[I].begin();it!=S[I].end();++it){
            aux = (*it);
            if(!first) ans[n] = min(ans[n],aux-prev);
            first = false;
            prev = aux;
        }
    }
    
    solved[n] = true;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    int aux;
    for(int i=1;i<n;++i){
        scanf("%d",&aux);
        --aux;
        L[aux].push_back(i);
    }
    
    fill(solved,solved+n,false);
    fill(repeated,repeated+n,false);
    
    for(int i=n-m;i<n;++i){
        scanf("%d",&aux);
        solved[i] = true;
        repeated[i] = false;
        S[i].insert(aux);
        ind[i] = i;
        ans[i] = aux;
    }
    
    for(int i=n-m-1;i>=0;--i)
        if(!solved[i])
            solve(i);
    
    printf("%d",ans[0]);
    for(int i=1;i<n-m;++i) printf(" %d",ans[i]);
    printf("\n");
    
    return 0;
}
