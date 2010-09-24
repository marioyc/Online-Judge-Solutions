#include<iostream>
#include<queue>

using namespace std;

int N,M,X;
int visited[1000];
int T[1000][1000];

struct nodo{
    int pos;
    int time;
    
    nodo(int a, int b){
        pos=a;
        time=b;
    }
};

void bfs(){
    queue<nodo> Q;
    
    Q.push(nodo(X,0));
    
    while(!Q.empty()){
        nodo aux=Q.front();
        Q.pop();
        
        
        if(visited[aux.pos]<=aux.time) continue;
        
        visited[aux.pos]=aux.time;
        
        for(int i=0;i<N;i++)
            if(T[aux.pos][i]!=(1<<20)) Q.push(nodo(i,aux.time+T[aux.pos][i]));
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d %d %d",&N,&M,&X);
    X--;
    
    int a,b,t;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) T[i][j]=(1<<20);
    
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&t);
        a--;
        b--;
        T[a][b]=min(T[a][b],t);
        T[b][a]=T[a][b];
    }
    
    fill(visited,visited+N,(1<<20));
    
    bfs();
    
    int max_time=-1;
    
    for(int i=0;i<N;i++) max_time=max(max_time,visited[i]);
    
    printf("%d\n",2*max_time);
    
    return 0;
}
