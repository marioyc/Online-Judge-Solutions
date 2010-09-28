#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int tc=1,u,v,N,E,parent[1000],cont,aux;
    bool valid,active[1000],in[1000],visited[1000];
    vector< vector<int> > L(1000);
    
    while(1){
        fill(parent,parent+1000,-1);
        fill(active,active+1000,false);
        fill(in,in+1000,false);
        valid=true;
        E=0;
        
        for(int i=0;i<1000;i++) L[i].clear();
        
        while(1){
            scanf("%d %d",&u,&v);
            if(u<=0 || v<=0) break;
            E++;
            u--; v--;
            active[u]=active[v]=true;
            if(u==v) valid=false;
            L[u].push_back(v);
            in[v]=true;
        }
        
        if(u<0 || v<0) break;
        
        N=count(active,active+1000,true);
        
        if(N!=0 && E!=N-1) valid=false;
        
        if(valid){
            for(int i=0;i<1000;i++){
                if(active[i] && !in[i]){
                    queue<int> Q;
                    Q.push(i);
                    
                    fill(visited,visited+1000,false);
                    visited[i]=true;
                    
                    while(!Q.empty() && valid){
                        aux=Q.front();
                        Q.pop();
                        
                        for(int j=L[aux].size()-1;j>=0;j--){
                            if(visited[L[aux][j]]) valid=false;
                            else{
                                Q.push(L[aux][j]);
                                visited[L[aux][j]]=true;
                            }
                        }
                    }
                    
                    if(count(visited,visited+1000,true)!=N) valid=false;
                    break;
                }
            }
        }
        
        if(valid) printf("Case %d is a tree.\n",tc);
        else printf("Case %d is not a tree.\n",tc);
        tc++;
    }
    
    return 0;
}
