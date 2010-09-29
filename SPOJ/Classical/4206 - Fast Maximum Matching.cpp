#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_V1 50000
#define MAX_V2 50000
#define MAX_E 150000

int V1,V2,l[MAX_V1],r[MAX_V2];
int E,to[MAX_E],next[MAX_E],last[MAX_V1];
bool visited[MAX_V1];

void init(){
	memset(last,-1,sizeof(int)*V1);
	E = 0;
}
 
void add_edge(int u, int v){
	to[E] = v, next[E] = last[u]; last[u] = E; ++E;
}

bool pairup(int u){
    if (visited[u])  return false;
    visited[u] = true;
    
    for(int e = last[u];e!=-1;e = next[e]){
        int v = to[e];
        
        if(r[v]==-1 || pairup(r[v])){
            l[u] = v;
            r[v] = u;
            return true;
        }
    }
    
    return false;
}

int hopcroft_karp(){
    bool change = true;
    memset(l,-1,sizeof(int)*V1);
    memset(r,-1,sizeof(int)*V2);
    
    while(change){
        change = false;
        memset(visited,false,sizeof(bool)*V1);
        
        for(int i = 0;i<V1;++i)
            if(l[i]==-1) change |= pairup(i);
    }
    
    int ret = 0;
    
    for(int i = 0;i<V1;++i)
        if(l[i]!=-1) ++ret;
    
    return ret;
}

void readInt(int &n){
	int sign = 1;
	char c;
    n = 0;
    
    while(true){
    	c = getc(stdin);
    	
        switch( c ){
			case '-' :
				sign = -1;
            case ' ':
            	goto jump;
            case '\n':
            	goto jump;
            default:
            	n *= 10; 
            	n += c-'0';
            	break;
        }
    }
    
	jump:
    	n *= sign;
}

int main(){
	int e,u,v;
	readInt(V1);
	readInt(V2);
	readInt(e);
	
	init();
	
	while(e--){
		readInt(u); readInt(v);
		--u; --v;
		add_edge(u,v);
	}
	
	printf("%d\n",hopcroft_karp());
	
	return 0;
}

