#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int visited[50001],Q[50001],head,tail;
int cur,nxt;

int solve(int M, int a, int b){
    memset(visited,-1,sizeof(visited));
    head = tail = 0;
    
    visited[a] = 0;
    Q[tail] = a; ++tail;
    
    while(true){
        cur = Q[head]; ++head;
        
        if(cur==b) return visited[b];
        
        int dist = visited[cur]+1;
        
        nxt = cur+1;
        
        if(nxt<=M && visited[nxt]==-1){
            visited[nxt] = visited[cur]+1;
            Q[tail] = nxt; ++tail;
        }
        
        nxt = min(M,cur*2);
        
        if(nxt<=M && visited[nxt]==-1){
            visited[nxt] = visited[cur]+1;
            Q[tail] = nxt; ++tail;
        }
        
        nxt = cur-1;
        
        if(nxt>=0 && visited[nxt]==-1){
            visited[nxt] = visited[cur]+1;
            Q[tail] = nxt; ++tail;
        }
    }
    
    return -1;
}

int main(){
    int M,a,b;
    
    while(scanf("%d %d %d",&M,&a,&b)==3)
        printf("%d\n",solve(M,a,b));
    
    return 0;
}
