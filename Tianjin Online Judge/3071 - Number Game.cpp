#include <cstdio>
#include <algorithm>

using namespace std;

int Q[100000],head,tail,x,visited[100000];

int solve(int &s, int &e){
    head=0; Q[0]=s; tail=1;
    
    fill(visited,visited+100000,-1);
    visited[s]=0;
    
    while(head!=tail){
        x=Q[head++];
        if(x==e) return visited[x];
        
        if(x<50000 && visited[2*x]==-1){
            Q[tail++]=2*x;
            visited[2*x]=visited[x]+1;
        }
        
        if((x&1)==0 && visited[x>>1]==-1){
            Q[tail++]=(x>>1);
            visited[x>>1]=visited[x]+1;
        }
        
        if(x<99999 && visited[x+1]==-1){
            Q[tail++]=x+1;
            visited[x+1]=visited[x]+1;
        }
    }
    
    return -1;
}

int main(){
    int T,s,e;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&s,&e);
        printf("%d\n",solve(s,e));
    }
    
    return 0;
}
