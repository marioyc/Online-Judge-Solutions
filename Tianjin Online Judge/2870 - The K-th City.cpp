#include<queue>
#include<vector>
#include<map>
#include<iostream>

using namespace std;

int N, M, K;
vector< vector< pair<int,int> > > v;
bool X[200];

struct nodo{
    int a;
    int cost;
    
    nodo(int x, int y){
        a=x;
        cost=y;
    }
    
    bool operator < (nodo Y)const{
        if(cost==Y.cost) return a>Y.a;
        
        return cost>Y.cost;
    }
};
int cont;

void bfs(){
    priority_queue<nodo> Q;
    
    X[0]=1;
    for(int i=0;i<v[0].size();i++)
        Q.push(nodo(v[0][i].first,v[0][i].second));
        
    while(1){
        nodo aux=Q.top();
        Q.pop();
        
        if(!X[aux.a]){
            cont++;
            X[aux.a]=1;
        }
        if(cont==K){
            cout<<aux.a<<endl;
            return;
        }
        
        for(int i=0;i<v[aux.a].size();i++)
            if(!X[v[aux.a][i].first])
                Q.push(nodo(v[aux.a][i].first,aux.cost+v[aux.a][i].second));        
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int a,b,c;
    
    while(cin>>N){
        if(N==0) break;
        
        cin>>M;
        
        v.clear();
        v.resize(N);        
        
        for(int i=0;i<M;i++){
            scanf("%d %d %d",&a,&b,&c);
            v[a].push_back(make_pair(b,c));
            v[b].push_back(make_pair(a,c));
        }
        
        cin>>K;
        
        memset(X,0,sizeof(X)); cont=0;
        
        bfs();
    }
}
