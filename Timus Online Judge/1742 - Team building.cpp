#include <cstdio>

using namespace std;

int to[100001];
int parent[100001];

bool in[100001];
int visited[100001];
int nv[100001],ne[100001];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 1;i <= n;++i)
        parent[i] = i;
    
    for(int i = 1,x;i <= n;++i){
        scanf("%d",&x);
        
        to[i] = x;
        Union(x,i);
        
        if(x != i)
            in[x] = true;
    }
    
    for(int i = 1;i <= n;++i){
        int r = Find(i);
        if(to[i] != i) ++ne[r];
        ++nv[r];
    }
    
    int ans1 = 0,ans2 = n;
    
    for(int i = 1;i <= n;++i){
        if(!in[i]) ++ans1;
        
        if(ne[i] > 0){
            if(ne[i] == nv[i]){
                int pos = i,j = 0;
                
                while(visited[pos] == 0){
                    visited[pos] = j++;
                    
                    pos = to[pos];
                }
                
                int len = j - visited[pos];
                ans2 -= len - 1;
                if(len == nv[i]) ++ans1;
            }
        }
    }
    
    printf("%d %d\n",ans1,ans2);
    
    return 0;
}
