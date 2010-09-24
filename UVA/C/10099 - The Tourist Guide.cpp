#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

struct edge{
    int v;
    int capacity;
    
    edge(int a, int b){
        v=a;
        capacity=b;
    }
};

vector< vector<edge> > L;
int visited[100];

void bfs(int &start){
    queue< pair<int, int> > Q;
    Q.push(make_pair(start,(1<<20)));
    pair<int, int> P;
    
    while(!Q.empty()){
        P=Q.front();
        Q.pop();
        
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
    
    int N,R,C1,C2,P,S,D,T,cont;
    cont=1;
    
    while(1){
        scanf("%d %d",&N,&R);
        if(N==0 && R==0) break;
        
        L.clear();
        L.resize(N);
        
        for(int i=0;i<R;i++){
            scanf("%d %d %d",&C1,&C2,&P);
            L[C1-1].push_back(edge(C2-1,P));
            L[C2-1].push_back(edge(C1-1,P));
        }
        
        scanf("%d %d %d",&S,&D,&T);
        
        if(S==D){
            printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",cont,0);
            cont++;
            continue;
        }
        
        S--;
        D--;
        
        memset(visited,-1,sizeof(visited));
        
        bfs(S);
        
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",cont,(T+visited[D]-2)/(visited[D]-1));
        cont++;
    }
    
    return 0;
}
