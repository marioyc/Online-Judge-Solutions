#include <cstdio>
#include <map>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

#define SZ 100

bool M[SZ][SZ],print[SZ];
int N,colour[SZ],dfsNum[SZ],pos[SZ],leastAncestor[SZ],parent[SZ];

int Articulation_points(int u){
    int ans=0,cont=0,num=0,v;
    
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
    
    if(cont>1){
        ans++;
        print[u]=true;
    }
    
    for(int i=0;i<N;i++){
        if(i==u) continue;
        for(int j=0;j<N;j++)
            if(M[i][j] && parent[j]==i && leastAncestor[j]>=dfsNum[i]){
                print[i]=true;
                ans++;
                break;
            }
    }
    
    return ans;
}

int main(){
    char s[31],s2[31];
    int tc=1,R,u,v,ans;
    bool start=true;
    
    map<string,int> ind;
    map<string,int> :: iterator it;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        ind.clear();
        
        for(int i=0;i<N;i++){
            scanf("%s",s);
            ind[s]=i;
        }
        
        memset(M,false,sizeof(M));
        memset(print,false,sizeof(print));
        
        scanf("%d",&R);
        
        for(int i=0;i<R;i++){
            scanf("%s %s",s,s2);
            u=ind[s]; v=ind[s2];
            M[u][v]=M[v][u]=true;
        }
        
        if(!start) printf("\n");
        start=false;
        
        memset(colour,0,sizeof(colour));
        ans=0;
        for(int i=0;i<N;i++) if(colour[i]==0) ans+=Articulation_points(i);
        
        printf("City map #%d: %d camera(s) found\n",tc++,ans);
        
        for(it=ind.begin();it!=ind.end();it++)
            if(print[it->second]) printf("%s\n",(it->first).c_str());
    }
    
    return 0;
}
