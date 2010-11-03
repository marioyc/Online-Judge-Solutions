#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_V 10000

vector< vector<int> > L;
vector< vector<int> > E;
int n,parent[MAX_V],way[MAX_V];
long long W[MAX_V-1];

int solve(int v){
    int cont = 1;
    
    for(int i=L[v].size()-1;i>=0;--i){
        int next = L[v][i];
        if(next==parent[v]) continue;
        
        int aux = solve(next);
        cont += aux;
        
        W[way[next]] *= aux*(n-aux);
    }
    
    return cont;
}

int main(){
    int k,sh,sc;
    scanf("%d %d %d %d",&n,&k,&sh,&sc);
    
    int a,b,w;
    L.resize(n);
    E.resize(n);
    
    for(int i=0;i+1<n;++i){
        scanf("%d %d %lld",&a,&b,&W[i]);
        --a; --b;
        L[a].push_back(b);
        E[a].push_back(i);
        L[b].push_back(a);
        E[b].push_back(i);
    }
    
    memset(parent,-1,sizeof(parent));
    parent[0] = -2;
    
    queue<int> Q;
    Q.push(0);
    
    while(!Q.empty()){
        int aux = Q.front();
        Q.pop();
        
        for(int i=L[aux].size()-1;i>=0;--i){
            int v = L[aux][i];
            if(parent[v]!=-1) continue;
            parent[v] = aux;
            Q.push(v);
            way[v] = E[aux][i];
        }
    }
    
    solve(0);
    
    pair<long long,int> id[n-1];
    for(int i=0;i+1<n;++i) id[i] = make_pair(W[i],i);
    sort(id,id+(n-1));

    if(sh<sc){
        printf("%d",id[n-2].second+1);
        for(int i=1;i<k;++i) printf(" %d",id[n-i-2].second+1);
    }else{
        printf("%d",id[0].second+1);
        for(int i=1;i<k;++i) printf(" %d",id[i].second+1);
    }

    printf("\n");
    
    return 0;
}

