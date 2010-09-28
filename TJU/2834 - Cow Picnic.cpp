#include<iostream>
#include<queue>
#include<set>

using namespace std;

bool visited[1000];
int L[1000][1000];
int gr[1000];

void bfs(int a){
    queue<int> Q;
    Q.push(a);
    
    int aux;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        if(visited[aux]) continue;
        visited[aux]=1;
        
        for(int i=0;i<gr[aux];i++) Q.push(L[aux][i]);
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int K,N,M;
    set<int> S;
    
    scanf("%d %d %d",&K,&N,&M);
    
    int aux1,aux2;
    
    for(int i=0;i<K;i++){
        scanf("%d",&aux1);
        S.insert(aux1-1);
    }
    
    fill(gr,gr+N,0);
    
    for(int i=0;i<M;i++){
        scanf("%d %d",&aux1,&aux2);
        
        aux1--; aux2--;
        
        L[aux1][gr[aux1]++]=aux2;
    }
    
    bool reachable[1000];
    
    fill(reachable,reachable+N,true);
    
    set<int> :: iterator it;
    
    for(it=S.begin();it!=S.end();it++){
        fill(visited,visited+N,false);
        
        bfs((*it));
        
        for(int i=0;i<N;i++) reachable[i] &= visited[i];
    }
    
    int cont=0;
    
    for(int i=0;i<N;i++)
        if(reachable[i]) cont++;
    
    printf("%d\n",cont);
    
    return 0;
}
