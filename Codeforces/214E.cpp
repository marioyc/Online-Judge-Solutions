#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 305

int n,a[MAXN][MAXN];
bool done[MAXN][MAXN][MAXN];
int memo[MAXN][MAXN][MAXN];

int dr[] = {1,0},dc[] = {0,1};

int solve(int r1, int c1, int r2, int c2){
    if(r1 == n - 1 && c1 == n - 1) return 0;
    
    int &ret = memo[r1][c1][r2];
    
    if(!done[r1][c1][r2]){
        done[r1][c1][r2] = true;
        ret = -90000000;
        
        for(int i = 0;i < 2;++i){
            int x1 = r1 + dr[i],y1 = c1 + dc[i];
            
            if(x1 < n && y1 < n){
                for(int j = 0;j < 2;++j){
                    int x2 = r2 + dr[j],y2 = c2 + dc[j];
                    
                    if(x2 < n && y2 < n){
                        int aux = solve(x1,y1,x2,y2);
                        if(x1 == x2 && y1 == y2) aux += a[x1][y1];
                        else aux += a[x1][y1] + a[x2][y2];
                        ret = max(ret,aux);
                    }
                }
            }
        }
    }
    
    return ret;
}

int main(){
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j)
            scanf("%d",&a[i][j]);
    
    printf("%d\n",solve(0,0,0,0) + a[0][0]);
    
    return 0;
}
