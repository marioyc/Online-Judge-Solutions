#include <fstream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

#define MAX_V 100010

int N,deg[MAX_V];
list<int> G[MAX_V],L;
bool visited[MAX_V];
stack<int> S;
queue<int> Q;

bool connected(){
	int cont = 0;	
	
    Q.push(0);
    visited[0] = true;
    
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        ++cont;
        
        for(list<int>::iterator w = G[v].begin();w!=G[v].end();++w){
            if(!visited[*w]){
                visited[*w] = true;
                Q.push(*w);
            }
        }
    }
    
    return cont==N;
}

bool eulerian(){
    if(!connected()) return false;

    for(int v = 1;v<=N;++v)
        if(deg[v]&1)
            return false;
    
    return true;
}

void take_edge(int v, int w){
    --deg[v]; --deg[w];
    G[v].pop_front();
    
    for(list<int>::iterator it = G[w].begin();it!=G[w].end();++it){
        if(*it==v) {
            G[w].erase(it);
            break;
        }
    }
}

void euler(int v){
    while(true) {
        if(G[v].empty()) break;
        int w = G[v].front();
        S.push(v);
        take_edge(v,w);
        v = w;
    }
}

bool find_cycle(){
    if(!eulerian()) return false;
    
    int v = 0;
    
    do{
		euler(v);
        v = S.top(); S.pop();
        L.push_back(v);
    }while(!S.empty());
	
    return true;
}

void print_cycle(){
    if(!find_cycle()) printf("-1\n");
    else{
        for(list<int>::iterator v = L.begin();v!=L.end();++v)
			printf("%d ",1+(*v));
        printf("\n");
    }
}

int main() {
    freopen("ciclueuler.in","r",stdin);
    freopen("ciclueuler.out","w",stdout);
	
	int M,u,v;
	scanf("%d %d",&N,&M);
	
	while(M--){
		scanf("%d %d",&u,&v);
		--u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
		++deg[u]; ++deg[v];
	}
	
    print_cycle();

    return 0;
}
