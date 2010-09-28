#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>

using namespace std;

int c[402][402];
int f[402][402];
vector< vector<int> > L;
int t,n,v;
int prev[402];

bool augmenting(){
    fill(prev,prev+t+1,-1);
    
    queue<int> Q;
    Q.push(0);
    
    int aux;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        if(aux==t) break;
        
        n=L[aux].size();
        
        for(int i=0;i<n;i++){
            v=L[aux][i];
            
            if(prev[v]==-1 && f[aux][v]<c[aux][v]){
                prev[v]=aux;
                Q.push(v);
            }
        }
    }
    
    if(aux!=t) return false;
    
    int cur=t,next;    
    
    while(cur!=0){
        next=prev[cur];
        f[next][cur]++;
        f[cur][next]--;
        cur=next;
    }
    
    return true;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,F,D,fi,di,v;
    
    scanf("%d %d %d",&N,&F,&D);
    t=1+F+2*N+D;
    
    for(int i=0;i<t+1;i++){
        fill(c[i],c[i]+t+1,0);
        fill(f[i],f[i]+t+1,0);
    }
    
    L.resize(t+1);
    
    for(int i=0;i<F;i++){
        c[0][1+i]=1;
        L[0].push_back(1+i);
        L[1+i].push_back(0);
    }
    
    for(int i=0;i<N;i++){
        scanf("%d %d",&fi,&di);
        
        for(int j=0;j<fi;j++){
            scanf("%d",&v);
            c[v][1+F+i]=1;
            L[v].push_back(1+F+i);
            L[1+F+i].push_back(v);
        }
        
        c[1+F+i][1+F+N+i]=1;
        L[1+F+i].push_back(1+F+N+i);
        L[1+F+N+i].push_back(1+F+i);
        
        for(int j=0;j<di;j++){
            scanf("%d",&v);
            c[1+F+N+i][F+2*N+v]=1;
            L[1+F+N+i].push_back(F+2*N+v);
            L[F+2*N+v].push_back(1+F+N+i);
        }
    }
    
    for(int i=0;i<D;i++){
        c[1+F+2*N+i][t]=1;
        L[1+F+2*N+i].push_back(t);
        L[t].push_back(1+F+2*N+i);
    }
    
    int cows=0;
    
    while(augmenting()) cows++;
    
    printf("%d\n",cows);
    
    return 0;
}
