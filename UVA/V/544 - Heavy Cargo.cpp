#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>

using namespace std;

struct edge{
    int v;
    int capacity;
    
    edge(int a, int b){
        v=a;
        capacity=b;
    }
    
    bool operator < (edge X){
        return capacity>X.capacity;
    }
};

vector< vector<edge> > L;
int visited[200];

int bfs(int &start, int &end){
    priority_queue< pair<int, int> > Q;
    Q.push(make_pair(start,(1<<20)));
    
    pair<int, int> P;
    
    while(1){
        P=Q.top();
        Q.pop();
        
        if(P.first==end) return P.second;
        
        for(int i=0;i<L[P.first].size();i++)
            if(min(P.second,L[P.first][i].capacity)>visited[L[P.first][i].v]){
                visited[L[P.first][i].v]=min(P.second,L[P.first][i].capacity);
                
                Q.push(make_pair(L[P.first][i].v,visited[L[P.first][i].v]));
            }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string city1,city2;
    
    map<string, int> cities;
    
    int n,r,a,b,w,cont,scenario;
    scenario=1;    
    
    while(1){
        scanf("%d %d",&n,&r);
        if(n==0 && r==0) break;
        
        cities.clear();
        L.clear();
        L.resize(n);
        cont=0;
        
        for(int i=0;i<r;i++){
            cin>>city1>>city2;
            
            if(cities.find(city1)!=cities.end()) a=cities[city1];
            else{
                cities[city1]=cont;
                a=cont++;
            }
            
            if(cities.find(city2)!=cities.end()) b=cities[city2];
            else{
                cities[city2]=cont;
                b=cont++;
            }
            
            scanf("%d",&w);
            
            L[a].push_back(edge(b,w));
            L[b].push_back(edge(a,w));
        }
        
        memset(visited,-1,sizeof(visited));
        
        cin>>city1>>city2;
        a=cities[city1];
        b=cities[city2];
        
        printf("Scenario #%d\n%d tons\n\n",scenario,bfs(a,b));
        scenario++;
    }
    
    return 0;
}
