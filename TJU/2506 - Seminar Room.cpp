#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

#define MAX_V 40000

vector<int> L[MAX_V],C[MAX_V];
int V,dfsPos,dfsNum[MAX_V],lowlink[MAX_V],num_scc,comp[MAX_V];
bool in_stack[MAX_V];
stack<int> S;

void tarjan(int v){
    dfsNum[v] = lowlink[v] = dfsPos++;
    S.push(v); in_stack[v] = true;
    
    for(int i = L[v].size()-1;i>=0;--i){
        int w = L[v][i];
        if(dfsNum[w]==-1){
            tarjan(w);
            lowlink[v] = min(lowlink[v],lowlink[w]);
        }else if(in_stack[w]) lowlink[v] = min(lowlink[v], lowlink[w]);
    }
    
    if(dfsNum[v]==lowlink[v]){
        vector<int> &com = C[num_scc];
        com.clear();
        int aux;
        
        do{
            aux = S.top(); S.pop();
            comp[aux] = num_scc;
            com.push_back(aux);
            in_stack[aux] = false;
        }while(aux!=v);
        
        ++num_scc;
    }
}

void build_scc(int _V){
    V = _V;
    memset(dfsNum,-1,sizeof(dfsNum));
    memset(in_stack,false,sizeof(in_stack));
    dfsPos = num_scc = 0;
    
    for(int i = 0;i<V;++i)
        if(dfsNum[i]==-1)
            tarjan(i);
}

int main(){
    int T,N,hh,mm,s[2000],e[2000];
    char ddd[4];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d\n",&N);
        
        for(int i = 0;i<2*N;++i){
            scanf("%c%c%c:%d:%d%*[ \n]",&ddd[0],&ddd[1],&ddd[2],&hh,&mm);
            
            if(ddd[0]=='M') s[i] = 60*hh+mm;
            else if(ddd[0]=='T' && ddd[1]=='U') s[i] = 1440+60*hh+mm;
            else if(ddd[0]=='W') s[i] = 1440*2+60*hh+mm;
            else if(ddd[0]=='T' && ddd[1]=='H') s[i] = 1440*3+60*hh+mm;
            else if(ddd[0]=='F') s[i] = 1440*4+60*hh+mm;
            else s[i] = 1440*5+60*hh+mm;
            
            scanf("%c%c%c:%d:%d%*[ \n]",&ddd[0],&ddd[1],&ddd[2],&hh,&mm);
            
            if(ddd[0]=='M') e[i] = 60*hh+mm;
            else if(ddd[0]=='T' && ddd[1]=='U') e[i] = 1440+60*hh+mm;
            else if(ddd[0]=='W') e[i] = 1440*2+60*hh+mm;
            else if(ddd[0]=='T' && ddd[1]=='H') e[i] = 1440*3+60*hh+mm;
            else if(ddd[0]=='F') e[i] = 1440*4+60*hh+mm;
            else e[i] = 1440*5+60*hh+mm;
            
            L[i].clear();
            L[2*N+i].clear();
        }
        
        for(int i = 0;i<2*N;i += 2){
            L[2*N+i+1].push_back(i);
            L[2*N+i].push_back(i+1);
        }
        
        for(int i = 2*N-1;i>=0;--i){
            for(int j = 2*N-1;j>i;--j){
                if(!(e[i]<=s[j] || s[i]>=e[j])){
                    L[i].push_back(2*N+j);
                    L[j].push_back(2*N+i);
                }
            }
        }
        
        build_scc(4*N);
        
        bool valid = true;
        
        for(int i = 2*N-1;i>=0;--i)
            if(comp[i]==comp[2*N+i])
                valid = false;
        
        if(valid) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
