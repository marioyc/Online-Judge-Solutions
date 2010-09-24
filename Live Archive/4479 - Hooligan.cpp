#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_V 3005
#define MAX_E 8931

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
    
    int x=INT_MAX;
    
    for(int i=0;i<sz;i++) x=min(x,cap[path[i]]-flow[path[i]]);
    
    f+=x;
    
    for(int i=0;i<sz;i++){
        flow[path[i]]+=x;
        flow[path[i]^1]-=x;
    }
    
    return true;
}


int main(){
    int N,M,G,a,b,games[40][40],res,points[40],m;
    char sign;
    bool can;
    
    while(1){
        scanf("%d %d %d",&N,&M,&G);
        if(N==0) break;
        
        for(int i=0;i<N;i++) fill(games[i],games[i]+N,M);
        fill(points,points+N,0);
        
        res=M*N*(N-1)/2-G;
        
        for(int i=0;i<G;i++){
            scanf("%d %c %d",&a,&sign,&b);
            games[a][b]--; games[b][a]--;
            if(sign=='='){
                points[a]++;
                points[b]++;
            }else points[b]+=2;
        }
        
        for(int i=1;i<N;i++){
            points[0]+=2*games[0][i];
            res-=games[0][i];
        }
        
        can=true;
        for(int i=1;i<N;i++) if(points[i]>=points[0]) can=false;
        
        if(!can){
            printf("N\n");
            continue;
        }
        
        V=1+res+N;
        E=0;
        
        fill(next,next+2*MAX_E,-1);
        fill(last,last+V,-1);
        
        for(int i=1;i<=res;i++){
            to[E]=i;
            cap[E]=2;
            next[E]=last[0];
            last[0]=E++;
            
            to[E]=0;
            cap[E]=0;
            next[E]=last[i];
            last[i]=E++;
        }
        
        m=1;
        
        for(int i=1;i<N;i++){
            for(int j=i+1;j<N;j++){
                for(int k=0;k<games[i][j];k++){
                    to[E]=res+i;
                    cap[E]=2;
                    next[E]=last[m];
                    last[m]=E++;
                    
                    to[E]=m;
                    cap[E]=0;
                    next[E]=last[res+i];
                    last[res+i]=E++;
                    
                    to[E]=res+j;
                    cap[E]=2;
                    next[E]=last[m];
                    last[m]=E++;
                    
                    to[E]=m;
                    cap[E]=0;
                    next[E]=last[res+j];
                    last[res+j]=E++;
                    
                    m++;
                }
            }
        }
        
        for(int i=1;i<N;i++){
            to[E]=V-1;
            cap[E]=points[0]-points[i]-1;
            next[E]=last[res+i];
            last[res+i]=E++;
            
            to[E]=res+i;
            cap[E]=0;
            next[E]=last[V-1];
            last[V-1]=E++;
        }
        
        fill(flow,flow+E,0);
        t=V-1;
        f=0;
        
        while(augmenting()) ;
        
        if(f==res*2) printf("Y\n");
        else printf("N\n");
    }
    
    return 0;
}
