#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,P,K;
    scanf("%d %d %d",&N,&P,&K);
    
    int u,v,w,W[10001];
    vector< vector< pair<int, int> > > L(N);
    
    W[0]=0;
    
    for(int i=0;i<P;i++){
        scanf("%d %d %d",&u,&v,&w);
        u--; v--;
        L[u].push_back(make_pair(v,w));
        L[v].push_back(make_pair(u,w));
        W[i+1]=w;
    }
    
    sort(W,W+P);
    
    int lo=0,hi=P,mi,l;
    
    int Q[1000];
    int s1,s2,Qsize;
    bool solved,visited[1000];
    pair<int, int> p;
    
    while(1){
        mi=(lo+hi)>>1;
        l=W[mi];
        
        s1=0; Qsize=0;
        fill(visited,visited+N,false);
        Q[Qsize++]=0;
        visited[0]=true;
        
        solved=false;
        
        for(int x=0;x<=K && !solved;x++){
            for(int i=s1;i<Qsize && !solved;i++){
                if(Q[i]==N-1) solved=true;
                
                for(int j=L[Q[i]].size()-1;j>=0;j--){
                    p=L[Q[i]][j];
                    u=p.first;
                    v=p.second;
                    
                    if(v<=l && !visited[u]){
                        Q[Qsize++]=u;
                        visited[u]=true;
                    }
                }
            }
            
            if(solved) break;
            
            s2=s1;
            s1=Qsize;
            
            for(int i=s2;i<s1;i++){
                for(int j=L[Q[i]].size()-1;j>=0;j--){
                    p=L[Q[i]][j];
                    u=p.first;
                    v=p.second;
                    
                    if(v>l && !visited[u]){
                        Q[Qsize++]=u;
                        visited[u]=true;
                    }
                }
            }
        }
        
        if(lo==hi){
            if(!solved) printf("-1\n");
            else printf("%d\n",W[lo]);
            break;
        }else{
            if(!solved) lo=mi+1;
            else hi=mi;
        }
    }
    
    return 0;
}
