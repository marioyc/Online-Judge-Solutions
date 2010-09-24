#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

#define SZ 100

bool M[SZ][SZ];
int N,colour[SZ],dfsNum[SZ],pos[SZ],leastAncestor[SZ],parent[SZ];

int Articulation_points(int u){
    int ans=0,cont=0,num=0,v;
    
    memset(colour,0,sizeof(colour));
    memset(pos,0,sizeof(pos));
    memset(parent,-1,sizeof(parent));
    
    stack<int> S;
    S.push(u);
    
    while(!S.empty()){
        v=S.top();
        if(colour[v]==0){
            colour[v]=1;
            dfsNum[v]=num++;
            leastAncestor[v]=num;
        }
        
        for(;pos[v]<N;pos[v]++){
            if(M[v][pos[v]] && pos[v]!=parent[v]){
                if(colour[pos[v]]==0){
                    parent[pos[v]]=v;
                    S.push(pos[v]);
                    if(v==u) cont++;
                    break;
                }else leastAncestor[v]<?=dfsNum[pos[v]];
            }
        }
        
        if(pos[v]==N){
            colour[v]=2;
            S.pop();
            
            if(v!=u) leastAncestor[parent[v]]<?=leastAncestor[v];
        }
    }
    
    if(cont>1) ans++;
    
    for(int i=0;i<N;i++){
        if(i==u) continue;
        for(int j=0;j<N;j++)
            if(M[i][j] && parent[j]==i && leastAncestor[j]>=dfsNum[i]){
                ans++;
                break;
            }
    }
    
    return ans;
}

int main(){
    int u,v;
    string s;
    
    while(1){
        scanf("%d\n",&N);
        if(N==0) break;
        
        memset(M,false,sizeof(M));
        
        while(1){
            getline(cin,s);
            istringstream is(s);
            
            is>>u;
            if(u==0) break;
            u--;
            
            while(is>>v){
                v--;
                M[u][v]=M[v][u]=true;
            }
        }
        
        printf("%d\n",Articulation_points(0));
    }
    
    return 0;
}
