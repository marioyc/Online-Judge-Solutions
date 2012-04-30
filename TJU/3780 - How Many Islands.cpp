#include <cstdio>

using namespace std;

int parent[2500];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

int main(){
    int n,m;
    int M[50][50];
    
    while(true){
        scanf("%d %d",&m,&n);
        
        if(n == 0) break;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                scanf("%d",&M[i][j]);
        
        for(int i = n*m - 1;i >= 0;--i)
            parent[i] = i;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                if(M[i][j] == 1)
                    for(int dr = -1;dr <= 1;++dr)
                        for(int dc = -1;dc <= 1;++dc)
                            if(i + dr >= 0 && i + dr < n && j + dc >= 0 && j + dc < m && M[i + dr][j + dc] == 1)
                                Union(m * i + j, m * (i + dr) + j + dc);
        
        int ans = 0;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                if(M[i][j] == 1 && Find(m * i + j) == m * i + j)
                    ++ans;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
