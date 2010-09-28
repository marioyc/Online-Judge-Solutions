#include<iostream>
#include<queue>

using namespace std;

int roads[1000][1000];
int visited[1000];

int N,M,S,E;

struct nodo{
    int pos;
    int dist;
    
    nodo(int a, int b){
        pos=a;
        dist=b;
    }
    
    bool operator < (nodo X) const{
        return dist>X.dist;
    }
};

int shortest_path(){
    priority_queue<nodo> Q;
    
    Q.push(nodo(S,0));
    
    while(!Q.empty()){
        nodo aux=Q.top();
        Q.pop();
        
        if(aux.pos==E) return aux.dist;
        
        if(visited[aux.pos]<=aux.dist) continue;
        
        visited[aux.pos]=aux.dist;
        
        for(int i=0;i<N;i++)
            if(roads[aux.pos][i]!=2000)
                Q.push(nodo(i,aux.dist+roads[aux.pos][i]));
    }
    
    return -1;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int T,A,B,C;
    
    cin>>T;
    
    for(int caso=0;caso<T;caso++){
        cin>>N>>M;
        
        cin>>S>>E;
        S--;
        E--;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) roads[i][j]=2000;
        
        for(int i=0;i<M;i++){
            cin>>A>>B>>C;
            A--; B--;
            
            roads[A][B]=min(roads[A][B],C);
            roads[B][A]=roads[A][B];
        }
        
        fill(visited,visited+N,(1<<20));
        
        cout<<shortest_path()<<endl;
    }
    
    return 0;
}
