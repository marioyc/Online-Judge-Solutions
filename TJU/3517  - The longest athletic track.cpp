#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

vector< vector<int> > L;
vector< vector<int> > W;
bool visited[2000];

pair<int,int> search(int s){
    memset(visited,false,sizeof(visited));
    
    queue< pair<int, int> > Q;
    Q.push(make_pair(s,0)); visited[s] = true;
    
    int e = s,w = 0;
    pair<int, int> aux;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        if(aux.second>w){
            e = aux.first;
            w = aux.second;
        }
        
        for(int i=L[aux.first].size()-1;i>=0;--i){
            int v = L[aux.first][i];
            if(visited[v]) continue;
            Q.push(make_pair(v,aux.second+W[aux.first][i]));
            visited[v] = true;
        }
    }
    
    return make_pair(e,w);
}

int main(){
    int T,N,a,b,c;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&N);
        
        L.clear(); L.resize(N);
        W.clear(); W.resize(N);
        
        for(int i=1;i<N;++i){
            scanf("%d %d %d",&a,&b,&c);
            --a; --b;
            L[a].push_back(b);
            W[a].push_back(c);
            L[b].push_back(a);
            W[b].push_back(c);
        }
        
        printf("%d\n",search(search(0).first).second);
    }
}
