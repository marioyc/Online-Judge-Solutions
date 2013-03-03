#include <cstdio>
#include <algorithm>

using namespace std;

int C,R;
char M[750][751];
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

int id(int r, int c){
    return r * C + c;
}

int parent[750*750],cont[750*750];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    
    if(x != y){
        parent[x] = y;
        cont[y] += cont[x];
    }
}

int main(){
    scanf("%d %d",&C,&R);
    
    for(int i = 0;i < R;++i)
        scanf("%s",M[i]);
    
    int N = R * C;
    
    for(int i = 0;i < N;++i){
        parent[i] = i;
        cont[i] = 1;
    }
    
    for(int i = 0;i < R;++i){
        for(int j = 0;j < C;++j){
            if(M[i][j] == '.'){
                for(int k = 0;k < 8;++k){
                    int r = i + dr[k];
                    int c = j + dc[k];
                    
                    if(r >= 0 && r < R && c >= 0 && c < C && M[r][c] == '.')
                        Union(id(i,j),id(r,c));
                }
            }
        }
    }
    
    int ans = 0;
    
    for(int i = 0;i < R;++i)
        for(int j = 0;j < C;++j)
            if(M[i][j] == '.')
                ans = max(ans,cont[ Find(id(i,j)) ]);
    
    printf("%d\n",ans);
    
    return 0;
}
