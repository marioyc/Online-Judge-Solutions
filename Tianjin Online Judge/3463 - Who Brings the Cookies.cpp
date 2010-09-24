#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_V 1102
#define MAX_E 3000

int V,E,t,f;
int flow[2*MAX_E],cap[2*MAX_E],to[2*MAX_E],next[2*MAX_E],last[MAX_V];
int path[MAX_V-1],sz;
bool visited[MAX_V],found;

void dfs(int u, int depth){
    if(u==t){
        sz=depth;
        found=true;
        return;
    }
    
    for(int v,num=last[u];num!=-1 && !found;num=next[num]){
        v=to[num];
        
        if(!visited[v] && flow[num]<cap[num]){
            visited[v]=true;
            path[depth]=num;
            dfs(v,depth+1);
        }
    }
}

bool augmenting(){
    fill(visited,visited+V,false);
    
    found=false;
    sz=0;
    dfs(0,0);
    
    if(!found) return false;
    
    f++;
    
    for(int i=0;i<sz;i++){
        flow[path[i]]++;
        flow[path[i]^1]--;
    }
    
    return true;
}

int main(){
    int N,M,e;
    int S[100],L[100][19];
    double sum[1000];
    
    scanf("%d %d",&N,&M);
    
    for(int i=0;i<M;i++){
        scanf("%d",&S[i]);
        for(int j=S[i]-1;j>=0;j--){
            scanf("%d",&L[i][j]);
            L[i][j]--;
        }
    }
    
    fill(sum,sum+N,0.0);
    
    for(int i=0;i<M;i++)
        for(int j=S[i]-1;j>=0;j--)
            sum[L[i][j]]+=1.0/S[i];
    
    V=N+M+2;
    E=N+M;
    
    for(int i=0;i<M;i++) E+=S[i];
    
    fill(last,last+2*V,-1);
    fill(next,next+2*E,-1);
    fill(flow,flow+2*E,0);
    fill(cap,cap+2*E,0);
    e=0;
    
    for(int i=0;i<N;i++){
        cap[e]=ceil(sum[i]);
        to[e]=1+i;
        next[e]=last[0];
        last[0]=e++;
        
        cap[e]=0;
        to[e]=0;
        next[e]=last[1+i];
        last[1+i]=e++;
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<S[i];j++){
            cap[e]=1;
            to[e]=1+N+i;
            next[e]=last[1+L[i][j]];
            last[1+L[i][j]]=e++;
            
            cap[e]=0;
            to[e]=1+L[i][j];
            next[e]=last[1+N+i];
            last[1+N+i]=e++;
        }
    }
    
    for(int i=0;i<M;i++){
        cap[e]=1;
        to[e]=1+N+M;
        next[e]=last[1+N+i];
        last[1+N+i]=e++;
        
        cap[e]=0;
        to[e]=1+N+i;
        next[e]=last[1+N+M];
        last[1+N+M]=e++;
    }
    
    t=N+M+1; f=0;
    
    while(augmenting()) ;
    
    if(f!=M) printf("-1\n");
    else{
        int ind[M];
        
        for(int i=2*E-1;i>=0;i--)
            if(to[i]>=1+N && to[i]<t && flow[i]==1)
                ind[to[i]-N-1]=to[i^1];
        
        for(int i=0;i<M;i++) printf("%d\n",ind[i]);
    }
    
    return 0;
}

