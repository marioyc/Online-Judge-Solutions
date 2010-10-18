#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int M;
vector< pair<int, int> > S,E;
set< pair<int, int> > V;
vector<int> L[200000];

int getID(pair<int, int> P){
    int lo = 0, hi = M-1, mi;
    
    while(lo!=hi){
        mi = (lo+hi)/2;
        
        if(S[mi]<P) lo = mi+1;
        else hi = mi;
    }
    
    return lo;
}

int main(){
    freopen("7427.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;
    bool visited[200000];
    
    while(true){
        scanf("%d",&N);
        if(N==-1) break;
        
        E.clear();
        E.resize(2*N);
        V.clear();
        
        for(int i = 2*N-1;i>=0;--i){
            scanf("%d %d",&E[i].first,&E[i].second);
            V.insert(E[i]);
        }
        
        S = vector< pair<int, int> >(V.begin(),V.end());
        M =  S.size();
        
        int comp = 0, ans = 0;
        
        for(int i = 0;i<M;++i) L[i].clear();
        
        for(int i = 0;i<N;++i){
            int u = getID(E[2*i]), v = getID(E[2*i+1]);
            
            L[u].push_back(v);
            L[v].push_back(u);
        }
        
        memset(visited,0,sizeof(visited));
        
        for(int i = 0;i<M;++i){
            if(visited[i]) continue;
            ++comp;
            
            queue<int> Q;
            Q.push(i);
            visited[i] = true;
            
            while(!Q.empty()){
                int aux = Q.front();
                Q.pop();
                
                for(int e = L[aux].size()-1;e>=0;--e){
                    int v = L[aux][e];
                    
                    if(!visited[v]){
                        visited[v] = true;
                        Q.push(v);
                    }
                }
            }
        }
        
        printf("%d\n",comp-M+N);
    }
    
    return 0;
}
