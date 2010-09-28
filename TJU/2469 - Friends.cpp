#include<iostream>
#include<queue>

using namespace std;

bool visited[100];

vector< vector<int> > L;

void bfs(int a){
    queue<int> Q;
    
    visited[a]=true;
    Q.push(a);
    
    while(!Q.empty()){
        int aux=Q.front();
        Q.pop();
        
        for(int i=0;i<L[aux].size();i++){
            if(!visited[L[aux][i]]){
                visited[L[aux][i]]=true;
                Q.push(L[aux][i]);
            }
        }
    }
}

int main(){
    int T,N,M,a,b,cont;
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>N>>M;
        
        L.clear();
        L.resize(N);
        
        for(int j=0;j<M;j++){
            cin>>a>>b;
            L[a-1].push_back(b-1);
            L[b-1].push_back(a-1);
        }
        
        cont=0;
        memset(visited,false,sizeof(visited));
        
        for(int j=0;j<N;j++){
            if(!visited[j]){
                cont++;
                bfs(j);
            }
        }
        
        cout<<cont<<endl;
    }
    
    return 0;
}
