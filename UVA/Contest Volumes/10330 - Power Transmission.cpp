#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int flow[202][202];
int cap[202][202];
vector< vector<int> > L;
int prev[202];

bool augmenting(int &f){
    fill(prev,prev+(2*N+2),-1);
    
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
                if(L[aux][i]==2*N+1) goto found;
                Q.push(L[aux][i]);
            }
    }
    
    return false;
    
    found:
    
    aux=INT_MAX;
    int cur=2*N+1,next;
    
    while(cur!=0){
        next=prev[cur];
        aux=min(aux,cap[next][cur]-flow[next][cur]);
        cur=next;
    }
    
    cur=2*N+1;
    
    while(cur!=0){
        next=prev[cur];
        flow[next][cur]+=aux;
        flow[cur][next]-=aux;
        cur=next;
    }
    
    f+=aux;
    
    return true;
}

int main(){
    int M,B,D,a,b,c,f;
    int N1=1,N2;
    
    while(scanf("%d",&N)==1){
        N2=N+1;
        
        for(int i=0;i<2*N+2;i++){
            fill(flow[i],flow[i]+2*N+2,0);
            fill(cap[i],cap[i]+2*N+2,0);
        }
        
        L.clear();
        L.resize(2*N+2);
        
        for(int i=0;i<N;i++){
            scanf("%d",&a);
            cap[N1+i][N2+i]=a;
            L[N1+i].push_back(N2+i);
            L[N2+i].push_back(N1+i);
        }
        
        scanf("%d",&M);
        
        for(int i=0;i<M;i++){
            scanf("%d %d %d",&a,&b,&c);
            a--; b--;
            cap[N2+a][N1+b]=c;
            L[N2+a].push_back(N1+b);
            L[N1+b].push_back(N2+a);
        }
        
        scanf("%d %d",&B,&D);
        
        for(int i=0;i<B;i++){
            scanf("%d",&a);
            a--;
            cap[0][N1+a]=INT_MAX;
            L[0].push_back(N1+a);
            L[N1+a].push_back(0);
        }
        
        for(int i=0;i<D;i++){
            scanf("%d",&a);
            a--;
            cap[N2+a][2*N+1]=INT_MAX;
            L[N2+a].push_back(2*N+1);
            L[2*N+1].push_back(N2+a);
        }
        
        f=0;
        while(augmenting(f)) ;
        
        printf("%d\n",f);
    }
    
    return 0;
}
