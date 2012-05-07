#include <cstdio>

using namespace std;

int parent[10000],sz[10000],cont[10000];

int Find(int x){
    if(parent[x] != x){
        int p = Find(parent[x]);
        cont[x] += cont[ parent[x] ];
        parent[x] = p;
    }
    
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    
    if(x != y){
        parent[x] = y;
        sz[y] += sz[x];
        ++cont[x];
    }
}

int main(){
    int T,N,Q,A,B;
    char s[2];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&N,&Q);
        
        printf("Case %d:\n",tc);
        
        for(int i = 1;i <= N;++i){
            parent[i] = i;
            sz[i] = 1;
            cont[i] = 0;
        }
        
        while(Q--){
            scanf("%s",s);
            
            if(s[0] == 'T'){
                scanf("%d %d",&A,&B);
                
                Union(A,B);
            }else{
                scanf("%d",&A);
                
                int r = Find(A);
                
                printf("%d %d %d\n",r,sz[r],cont[A]);
            }
        }
    }
    
    return 0;
}
