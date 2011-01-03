#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define SZ 98

int flow[SZ][SZ],cap[SZ][SZ],prev[SZ],f;
vector< vector<int> > L(SZ);

bool augmenting(int &N, int t){
    fill(prev,prev+N,-1);
    queue<int> Q;
    Q.push(0);
    prev[0]=-2;
    
    int aux;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        for(int i=0;i<L[aux].size();i++)
            if(flow[aux][L[aux][i]]<cap[aux][L[aux][i]] && prev[L[aux][i]]==-1){
                prev[L[aux][i]]=aux;
                if(L[aux][i]==t) goto found;
                Q.push(L[aux][i]);
            }
    }
    
    return false;
    
    found:
    
    int x=INT_MAX,cur=t,next;
    
    while(cur!=0){
        next=prev[cur];
        x=min(x,cap[next][cur]-flow[next][cur]);
        cur=next;
    }
    
    f+=x;
    cur=t;
    
    while(cur!=0){
        next=prev[cur];
        flow[next][cur]+=x;
        flow[cur][next]-=x;
        cur=next;
    }
    
    return true;
}

int main(){
    int M,W,N,u,v,c;
    
    while(1){
        scanf("%d %d",&M,&W);
        if(M==0) break;
        
        N=2*M-2;
        
        for(int i=0;i<N;i++) L[i].clear();
        
        memset(cap,0,sizeof(cap));
        
        for(int i=2;i<M;i++){
            scanf("%d %d",&u,&c);
            u--;
            
            L[u].push_back(M-2+u);
            L[M-2+u].push_back(u);
            cap[u][M-2+u]=c;
        }
        
        f=0;
        
        for(int i=0;i<W;i++){
            scanf("%d %d %d",&u,&v,&c);
            u--; v--;
            
            if(u==0 && v==M-1) f+=c;
            else if(u==0){
                L[0].push_back(v);
                L[v].push_back(0);
                cap[0][v]=c;
            }else if(v==M-1){
                L[M-2+u].push_back(N-1);
                L[N-1].push_back(M-2+u);
                cap[M-2+u][N-1]=c;
            }else{
                L[M-2+u].push_back(v);
                L[v].push_back(M-2+u);
                L[M-2+v].push_back(u);
                L[u].push_back(M-2+v);
                cap[M-2+u][v]=c;
                cap[M-2+v][u]=c;
            }
        }
        
        memset(flow,0,sizeof(flow));
        while(augmenting(N,N-1)) ;
        
        printf("%d\n",f);
    }
    
    return 0;
}
