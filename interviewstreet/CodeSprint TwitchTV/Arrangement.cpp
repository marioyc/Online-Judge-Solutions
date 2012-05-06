#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int V,l[1000],r[1000];
vector<int> L[1000];
bool visited[1000];

bool dfs(int pos){
    if(visited[pos]) return 0;
    visited[pos] = 1;
    
    for(int i = L[pos].size() - 1,to;i >= 0;--i){
        to = L[pos][i];
        
        if(l[to] == -1 || dfs(l[to])){
            r[pos] = to;
            l[to] = pos;
            return 1;
        }
    }
    
    return 0;
}

char M[1000][1001];

#define MAX1 24

char memo[(1 << MAX1)][MAX1];

char solve(int mask, int last){
    if(mask == 0) return 1;
    
    char &ret = memo[mask][last];
    
    if(ret == -1){
        ret = 0;
        
        int aux = mask;
        
        while(aux){
            int x = __builtin_ctz(aux);
            
            if(M[last][x] == '1' && solve(mask ^ (1 << x),x)){
                ret = 1;
                break;
            }
            
            aux ^= (1 << x);
        }
    }
    
    return ret;
}

#define MAX2 10000000

bool found;
int N,path[1000],cont;
bool used[1000];

void search(int depth){
    ++cont;
    
    if(depth == N){
        found = true;
        return;
    }
    
    if(cont > MAX2)return;
    
    for(int i = L[ path[depth - 1] ].size() - 1,to;i >= 0;--i){
        to = L[ path[depth - 1] ][i];
        
        if(!used[to]){
            path[depth] = to;
            used[to] = true;
            
            search(depth + 1);
            
            if(found) return;
            used[to] = false;
        }
    }
}

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
		scanf("%d",&n);
		N = n;
		
		for(int i = 0;i < n;++i)
			scanf("%s",M[i]);
		
		bool done = false;
		
		if(n <= MAX1){
            memset(memo,-1,sizeof memo);
            
            for(int i = 0;i < n && !done;++i){
                if(solve((1 << n) - 1 - (1 << i),i)){
                    done = true;
                    printf("Yes");
                    
                    for(int j = 0,pos = i,mask = (1 << n) - 1 - (1 << pos);j < n;++j){
                        printf(" %d",pos);
                        
                        if(j + 1 < n){
                            for(int k = 0;k < n;++k){
                                if((mask & (1 << k)) && M[pos][k] == '1' && solve(mask ^ (1 << k),k)){
                                    pos = k;
                                    break;
                                }
                            }
                            
                            mask ^= (1 << pos);
                        }
                    }
                    
                    printf("\n");
                }
            }
            
            if(!done) puts("No");
            
            continue;
        }
        
        memset(used,false,sizeof used);
        found = false;
        cont = 0;
        
        for(int i = 0;i < n;++i){
            L[i].clear();
            
            for(int j = 0;j < n;++j)
                if(M[i][j] == '1')
                    L[i].push_back(j);
        }
        
        for(int s = 0;s < n && !done;++s){
            path[0] = s;
            used[s] = true;
            
            search(1);
            
            if(found){
                done = true;
                printf("Yes");
                
                for(int i = 0;i < n;++i)
                    printf(" %d",path[i]);
                
                printf("\n");
            }
            
            used[s] = false;
        }
        
        if(done) continue;
		
		for(int s = 0;s < n && !done;++s){
			for(int i = 0;i < n;++i)
				L[i].clear();
			
			for(int i = 0,x;i < n;++i)
				for(int j = 0;j < n;++j)
					if(M[i][j] == '1' && j != s)
						L[i].push_back(j);
			
			V = n;
			
			memset(l,-1,sizeof l);
			memset(r,-1,sizeof r);
			
			bool change = true;
			
			while(change){
				memset(visited,false,sizeof visited);
				change = 0;
				
				for(int i = 0;i < V;++i)
					if(r[i] == -1)
						change |= dfs(i);
			}
			
			int ans = 0;
			
			for(int i = 0;i < V;++i)
				if(r[i] != -1) ++ans;
			
			if(ans == n - 1){
                done = true;
				printf("Yes");
				
				int pos = s;
				
				for(int j = 0;j < n;++j){
					printf(" %d",pos);
					pos = r[pos];
				}
				
				printf("\n");
			}
		}
		
		if(!done) puts("No");
    }
    
    return 0;
}
