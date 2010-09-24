#include <cstdio>
#include <string>
#include <map>
#include <queue>

using namespace std;

int M;
map<string, int> ind;
int L[650][650],sz[650];
bool visited[650];
int Q[650],head,tail;

bool possible(const int s){
    head=tail=0;
    
    Q[tail++]=s;
    
    memset(visited,false,sizeof(visited));
    visited[s]=true;
    
    int aux;
    
    while(head!=tail){
        aux=Q[head++];
        
        for(int i=sz[aux]-1,v;i>=0;i--){
            v=L[aux][i];
            if(v>=M){
                Q[tail++]=v;
                if(tail==650) tail=0;
                visited[v]=true;
            }else if(v==s+1) return true;
        }
    }
    
    return false;
}

int main(){
    int P,N;
    char s1[100],s2[100];
    int city1[300],city2[300];
    
    while(1){
        scanf("%d",&M);
        if(M==0) break;
        
        ind.clear();
        N=0;
        
        for(int i=0;i<M;i++){
            scanf("%s",s1);
            ind[s1]=N++;
        }
        
        scanf("%d",&P);
        
        for(int i=0;i<P;i++){
            scanf("%s %s",s1,s2);
            if(ind.find(s1)==ind.end()) ind[s1]=N++;
            if(ind.find(s2)==ind.end()) ind[s2]=N++;
            city1[i]=ind[s1];
            city2[i]=ind[s2];
        }
        
        memset(sz,0,sizeof(sz));
        for(int i=0;i<P;i++) L[city1[i]][sz[city1[i]]++]=city2[i];
        
        bool ok=true;
        for(int i=0;i+1<M && ok;i++) ok=(ok && possible(i));
        
        if(ok) printf("The tour can be planned.\n");
        else printf("The tour cannot be planned with the given flight segments.\n");
    }
    
    return 0;
}
