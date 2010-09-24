#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define SZ 1002

short flow[SZ][SZ],cap[SZ][SZ];
int prev[SZ],f;
vector< vector<int> > L(SZ);

bool augmenting(int &N, int &t){
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
    
    int cur=t,next;
    
    f++;
    cur=t;
    
    while(cur!=0){
        next=prev[cur];
        flow[next][cur]++;
        flow[cur][next]--;
        cur=next;
    }
    
    return true;
}

int main(){
    int T,N,V,t,h,m,departure[500],arrival[500],a[500],b[500],c[500],d[500];
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        V=2*N+2;
        t=V-1;
        
        for(int i=0;i<N;i++){
            scanf("%d:%d %d %d %d %d",&h,&m,&a[i],&b[i],&c[i],&d[i]);
            departure[i]=h*60+m;
            arrival[i]=departure[i]+abs(a[i]-c[i])+abs(b[i]-d[i]);
        }
        
        memset(flow,0,sizeof(flow));
        memset(cap,0,sizeof(cap));
        
        for(int i=2*N+1;i>=0;i--) L[i].clear();
        
        for(int i=0;i<N;i++){
            L[0].push_back(i+1);
            L[i+1].push_back(0);
            cap[0][i+1]=1;
        }
        
        for(int i=0;i<N;i++){
            L[N+1+i].push_back(2*N+1);
            L[2*N+1].push_back(N+1+i);
            cap[N+1+i][2*N+1]=1;
        }
        
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(arrival[i]+abs(c[i]-a[j])+abs(d[i]-b[j])<departure[j]){
                    L[i+1].push_back(N+1+j);
                    L[N+1+j].push_back(i+1);
                    cap[i+1][N+1+j]=1;
                }
            }
        }
        
        f=0;
        while(augmenting(V,t)) ;
        
        printf("%d\n",N-f);
    }
    
    return 0;
}
